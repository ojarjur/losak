/**
 * Pair.java
 * Class to represent a Lisp pair.
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
class Pair {
    private Object ar, dr;

    public static Pair cons(Object ar, Object dr) {
	Pair p = new Pair();
	p.ar = ar;
	p.dr = dr;
	return p;
    }
    public static Object car(Object o) {
	if (o == null) {
	    return null;
	} else if (o instanceof Pair) {
	    return ((Pair)o).ar;
	} else {
	    return null;
	}
    }
    public static Object cdr(Object o) {
	if (o == null) {
	    return null;
	} else if (o instanceof Pair) {
	    if (((Pair)o).dr instanceof Input) {
		((Pair)o).dr = ((Input)(((Pair)o).dr)).getInput();
	    }
	    return ((Pair)o).dr;
	} else {
	    return null;
	}
    }
}
