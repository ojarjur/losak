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

    public static Pair initialInput(Object args, Reader in) {
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

class Output {
    private PrintStream[] destinations;

    public Output(PrintStream[] destinations) {
	if (destinations.length < 1) {
	    System.err.println("Internal error in Mini LOSAK interpreter.");
	    System.exit(-1);
	}
	this.destinations = destinations;
    }

    public void send(Object value) throws Exception {
	if (value != null) {
	    if (value instanceof Integer) {
		destinations[0].write(((Integer)value).intValue());
	    } else if ((value instanceof Pair) &&
		       (Pair.car(value) instanceof Integer) &&
		       (Pair.cdr(value) instanceof Integer)) {
		int car = ((Integer)Pair.car(value)).intValue();
		char cdr = (char)((Integer)Pair.cdr(value)).intValue();
		destinations[car].write(cdr);
	    }
	}
    }

    public void sendAll(Object valueList) throws Exception {
	if (valueList != null) {
	    if (valueList instanceof Pair) {
		send(Pair.car(valueList));
		sendAll(Pair.cdr(valueList));
	    } else {
		send(valueList);
	    }
	}
    }
}
