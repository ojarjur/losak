/**
 * MiniLosak.java
 * Cross platform Mini Losak interpreter.
 * Copyright (C) 2005, by Omar Jarjur
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
 *
 * @author Omar Jarjur
 * @version 1.1
 */
import java.io.*;

public class MiniLosak {
    private static final String[] primitives =
    { "car", "cdr", "cons", "atom", "number", "symbol", "quote",
      "cond", "let", "fn", "&", "|", "^", "~", "=", "<", ">",
      "+", "-", "*", "/", "%", ">>>", ">>", "<<"};

    private static int verbosity = 0;
    private static void log(String msg, int verbosity) {
	if (MiniLosak.verbosity >= verbosity) {
	    System.out.println(msg);
	}
    }

    public static String printPair(Pair expr) {
	StringBuffer buff = new StringBuffer("(");
	Object curr = expr;
	while(! atom(curr)) {
	    if (buff.length() > 1) {
		buff.append(" ");
	    }
	    buff.append(print(Pair.car(curr)));
	    curr = Pair.cdr(curr);
	}
	if (curr == null) {
	    buff.append(")");
	} else {
	    buff.append(" . " + print(curr) + ")");
	}
	return buff.toString();
    }

    public static String print(Object expr) {
	if (expr == null) {
	    return "()";
	} else if (expr instanceof String) {
	    return (String)expr;
	} else if (expr instanceof Integer) {
	    return ((Integer)expr).toString();
	} else if (expr instanceof Function) {
	    return "[FUNCTION]";
	} else if (expr instanceof Pair) {
	    return printPair((Pair)expr);
	}
	return "[ERROR]";
    }

    private static Object readString(BufferedReader in, boolean escaped)
	throws IOException
    {
	int currChar = in.read();
        if ((currChar == '\"') && (! escaped)) {
	    return null;
	} else if ((currChar == '\\') && (! escaped)) {
	    return readString(in, true);
	} else {
	    Object result = readString(in, false);
	    Integer c = new Integer(currChar);
	    if (escaped) {
		if (currChar == 'n') {
		    c = new Integer('\n');
		} else if (currChar == 'r') {
		    c = new Integer('\r');
		} else if (currChar == 't') {
		    c = new Integer('\t');
		} else if (currChar == ':') {
		    c = new Integer(';');
		}
	    }
	    return Pair.cons(c, result);
	}
    }
    protected static Object readString(BufferedReader in) throws IOException {
	log("Reading a string...", 1);
	return readString(in, false);
    }

    protected static Integer readNumber(int value, BufferedReader in)
	throws IOException
    {
	in.mark(2);
	int currChar = in.read();
	while ((currChar >= '0') &&
	       (currChar <= '9')) {
	    value *= 10;
	    value += (currChar - '0');
	    in.mark(2);
	    currChar = in.read();
	}
	in.reset();
	return new Integer(value);
    }
    protected static String readSymbol(int curr,
				       BufferedReader in) throws IOException
    {
	char[] cs = new char[1];
	StringBuffer buff = new StringBuffer();
	while ((curr != '.') &&
	       (curr != '\'') &&
	       (curr != '(') &&
	       (curr != ')') &&
	       (curr != ';') &&
	       (curr != '#') &&
	       (curr > 32)) {
	    cs[0] = (char)curr;
	    buff.append(cs);
	    in.mark(2);
	    curr = in.read();
	}
	in.reset();
	return buff.toString();
    }

    protected static Object readPair(BufferedReader in,
				     boolean dotted, Object curr)
	throws Exception
    {
	int currChar = in.read();
	if (currChar < 33) {
	    return readPair(in, dotted, curr);
	} else if ((currChar == ';') || (currChar == '#')) {
	    // discard line...
	    while ((currChar != '\n') && (currChar != '\r')) {
		currChar = in.read();
	    }
	    return readPair(in, dotted, curr);
	} else if (currChar == ')') {
	    return curr;
	} else if (currChar == '.') {
	    if (dotted) {
		throw new Exception("Too many periods in pair expression.");
	    }
	    return readPair(in, true, null);
	} else if (curr != null) {
	    throw new Exception("Too many cdrs in pair expression.");
	} else {
	    Object next = read(currChar, in);
	    if (dotted) {
		return readPair(in, true, next);
	    } else {
		Object rest = readPair(in, false, null);
		return Pair.cons(next, rest);
	    }
	}
    }

    public static Object read(int currChar, BufferedReader in)
	throws Exception
    {
	if (currChar == '.') {
	    throw new Exception("Unexpected period.");
	} else if (currChar == ')') {
	    throw new Exception("Unexpected closing parenthesis.");
	} else if (currChar == '\'') {
	    Object result = read(in.read(), in);
	    return Pair.cons("quote", result);
	} else if (currChar == '\"') {
	    return Pair.cons("quote", readString(in));
	} else if (currChar == '(') {
	    return readPair(in, false, null);
	} else if (currChar < 33) {
	    return read(in.read(), in);
	} else if ((currChar == ';') || (currChar == '#')) {
	    // discard line...
	    while ((currChar != '\n') && (currChar != '\r')) {
		currChar = in.read();
	    }
	    return read(in.read(), in);
	} else if ((currChar >= '0') &&
		   (currChar <= '9')) {
	    return readNumber((currChar - '0'), in);
	} else {
	    return readSymbol(currChar, in);
	}
    }

    private static boolean isPrimitive(Object expr) {
	if (expr == null) {
	    return true;
	} else if (expr instanceof Integer) {
	    return true;
	} else if (expr instanceof String) {
	    for (int i = 0; i < primitives.length; i++) {
		if (expr.equals(primitives[i])) {
		    return true;
		}
	    }
	}
	return false;
    }

    private static boolean atom(Object expr) {
	if (expr == null) {
	    return true;
	} else if (expr instanceof Pair) {
	    return false;
	}
	return true;
    }
    private static boolean eq(Object e1, Object e2) {
	if (atom(e1) && atom(e2)) {
	    return e1.equals(e2);
	}
	return false;
    }

    private static Object applyPrimitive(String op, Object args) {
	if (! (args instanceof Pair)) {
	    return null;
	} else if (op.equals("car")) {
	    if (Pair.car(args) instanceof Pair) {
		return Pair.car(Pair.car(args));
	    }
	} else if (op.equals("cdr")) {
	    if (Pair.car(args) instanceof Pair) {
		return Pair.cdr(Pair.car(args));
	    }
	} else if (op.equals("atom")) {
	    if (atom(Pair.car(args))) {
		return "t";
	    }
	} else if (op.equals("number")) {
	    if (Pair.car(args) instanceof Integer) {
		return "t";
	    }
	} else if (op.equals("symbol")) {
	    if (Pair.car(args) instanceof String) {
		return "t";
	    }
	} else if (op.equals("~")) {
	    if (Pair.car(args) instanceof Integer) {
		int value = ((Integer)Pair.car(args)).intValue();
		return new Integer(~value);
	    }
	} else if (op.equals("-")) {
	    if (Pair.car(args) instanceof Integer) {
		int value = ((Integer)Pair.car(args)).intValue();
		if ((Pair.cdr(args) instanceof Pair) &&
		    (Pair.car(Pair.cdr(args)) instanceof Integer)) {
		    int val2 = ((Integer)Pair.car(Pair.cdr(args))).intValue();
		    return new Integer(value - val2);
		}
		return new Integer(-value);
	    }
	} else if (! (Pair.cdr(args) instanceof Pair)) {
	    return null;
	} else if (op.equals("cons")) {
	    return Pair.cons(Pair.car(args), Pair.car(Pair.cdr(args)));
	} else if ((! (Pair.car(args) instanceof Integer)) ||
		   (! (Pair.car(Pair.cdr(args)) instanceof Integer))) {
	    return null;
	} else {
	    int val1 = ((Integer)Pair.car(args)).intValue();
	    int val2 = ((Integer)Pair.car(Pair.cdr(args))).intValue();
	    if (op.equals("=") && (val1 == val2)) {
		return "t";
	    } else if (op.equals(">") && (val1 > val2)) {
		return "t";
	    } else if (op.equals("<") && (val1 < val2)) {
		return "t";
	    } else if (op.equals(">>>")) {
		return new Integer(val1 >>> val2);
	    } else if (op.equals(">>")) {
		return new Integer(val1 >> val2);
	    } else if (op.equals("<<")) {
		return new Integer(val1 << val2);
	    } else if (op.equals("&")) {
		return new Integer(val1 & val2);
	    } else if (op.equals("|")) {
		return new Integer(val1 | val2);
	    } else if (op.equals("^")) {
		return new Integer(val1 ^ val2);
	    } else if (op.equals("+")) {
		return new Integer(val1 + val2);
	    } else if (op.equals("*")) {
		return new Integer(val1 * val2);
	    } else if (op.equals("/")) {
		return new Integer(val1 / val2);
	    } else if (op.equals("%")) {
		return new Integer(val1 % val2);
	    }
	}
	return null;
    }

    private static Object evalCond(Object cases, Environment env) {
	if (cases instanceof Pair) {
	    if ((Pair.car(cases) instanceof Pair) &&
		(eval(Pair.car(Pair.car(cases)), env) != null)) {
		if (Pair.cdr(Pair.car(cases)) instanceof Pair) {
		    return eval(Pair.car(Pair.cdr(Pair.car(cases))), env);
		} else {
		    return null;
		}
	    } else {
		return evalCond(Pair.cdr(cases), env);
	    }
	}
	return null;
    }

    private static Object evalLet(Object vars, Object expr, Environment env) {
	if (vars instanceof Pair) {
	    Environment env2 = env;
	    if (Pair.car(vars) instanceof Pair) {
		if (Pair.cdr(Pair.car(vars)) instanceof Pair) {
		    env2 = Environment.bind(Pair.car(Pair.car(vars)),
					    eval(Pair
						 .car(Pair
						      .cdr(Pair
							   .car(vars))),
						 env),
					    env);
		} else {
		    env2 = Environment.bind(Pair.car(Pair.car(vars)),
					    null, env);
		}
	    }
	    return evalLet(Pair.cdr(vars), expr, env2);
	} else {
	    return eval(expr, env);
	}
    }

    private static Object evalSF(String op, Object expr, Environment env) {
	if (op.equals("fn")) {
	    if (expr instanceof Pair) {
		if (Pair.cdr(expr) instanceof Pair) {
		    return new Function(Pair.car(expr), Pair.car(Pair.cdr(expr)), env);
		} else {
		    return new Function(Pair.car(expr), null, env);
		}
	    } else {
		return new Function(null, null, env);
	    }
	} else if (op.equals("quote")) {
	    return expr;
	} else if (op.equals("cond")) {
	    return evalCond(expr, env);
	} else if (op.equals("let")) {
	    if ((expr instanceof Pair) &&
		(Pair.cdr(expr) instanceof Pair)) {
		return evalLet(Pair.car(expr), Pair.car(Pair.cdr(expr)), env);
	    }
	    return null;
	}
	return null;
    }

    private static Object evalList(Object list, Environment env) {
	if (atom(list)) {
	    return eval(list, env);
	} else {
	    return Pair.cons(eval(Pair.car(list), env),
			     evalList(Pair.cdr(list), env));
	}
    }

    public static Object eval(Object expr, Environment env) {
	if (atom(expr)) {
	    if (isPrimitive(expr)) {
		return expr;
	    } else if (expr instanceof Function) {
		return expr;
	    } else if (expr instanceof String) {
		return Environment.find((String)expr, env);
	    }
	    return null;
	} else {
	    Object op = eval(Pair.car(expr), env);
	    if ((op instanceof String) &&
		(op.equals("quote") ||
		 op.equals("cond") ||
		 op.equals("let") ||
		 op.equals("fn"))) {
		return evalSF((String)op, Pair.cdr(expr), env);
	    } else {
		Object args = evalList(Pair.cdr(expr), env);
		if (op instanceof Function) {
		    return ((Function)op).apply(args);
		} else if ((op instanceof String) &&
			   isPrimitive(op)) {
		    return applyPrimitive((String)op, args);
		}
		return null;
	    }
	}
    }

    public static void main(String[] args) {
	BufferedReader in =
	    new BufferedReader(new InputStreamReader(System.in));
	Object sExpr = "foo";
	String exitStr = "exit";
	verbosity = 3;
	while (! exitStr.equals(sExpr)) {
	    System.out.print("expr> ");
	    try {
		sExpr = read(in.read(), in);
	        System.out.println(print(eval(sExpr,
					      Environment.emptyEnv)));
	    } catch (Exception e) {
		System.out.println(e.getMessage());
		e.printStackTrace();
	    }
	}
    }
}
