import java.io.*;

/**
 * IO.java
 * Class to represent the asynchronous I/O activities of a purely
 * functional program
 * Copyright (C) 2005 by Omar Jarjur
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
class Input {
    private Reader in;

    public Pair intialInput(Reader in) {
	Input stream = new Input();
	stream.in = in;
	return Pair.cons(null, stream);
    }

    public Pair intialInput(Pair args, Reader in) {
	Input stream = new Input();
	stream.in = in;
	return Pair.cons(args, stream);
    }

    public Pair getInput() {
	try {
	    if (in.ready()) {
		return Pair.cons(new Integer(in.read()), this);
	    } else {
		return Pair.cons(null, this);
	    }
	} catch (IOException e) {
	    return Pair.cons(null, this);
	}
    }
}
