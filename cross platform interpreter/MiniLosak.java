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
 * @version 1.2
 */
import java.io.*;

public class MiniLosak {
    private static final String[] primitives =
    { "car", "cdr", "cons", "atom", "number", "symbol", "quote",
      "cond", "let", "fn", "&", "|", "^", "~", "=", "<", ">",
      "+", "-", "*", "/", "%", ">>>", ">>", "<<"};

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
	Object test = null, result = null;
	while ((test == null) && (! atom(cases))) {
	    try {
		test = eval(Pair.car(Pair.car(cases)), env, null);
		if (test != null) {
		    result = Pair.car(Pair.cdr(Pair.car(cases)));
		}
	    } catch (Exception e) {
		test = null;
	    }
	    cases = Pair.cdr(cases);
	}
	return result;
    }

    private static Environment evalLet(Object vars, Environment env) {
	while (! atom(vars)) {
	    Object var = Pair.car(Pair.car(vars));
	    Object val = Pair.car(Pair.cdr(Pair.car(vars)));
	    try {
		val = eval(val, env, null);
	    } catch (Exception e) {
		val = null;
	    }
	    env = Environment.bind(var, val, env);
	    vars = Pair.cdr(vars);
	}
	return env;
    }

    private static Object evalFN(Object expr, Environment env) {
	if (expr instanceof Pair) {
	    if (Pair.cdr(expr) instanceof Pair) {
		return new Function(Pair.car(expr),
				    Pair.car(Pair.cdr(expr)), env);
	    } else {
		return new Function(Pair.car(expr), null, env);
	    }
	} else {
	    return new Function(null, null, env);
	}
    }

    private static Object evalList(Object list, Environment env) {
	try {
	    if (atom(list)) {
		return eval(list, env, null);
	    } else {
		return Pair.cons(eval(Pair.car(list), env, null),
				 evalList(Pair.cdr(list), env));
	    }
	} catch (Exception e) {
	    return null;
	}
    }

    public static Object eval(Object expr, Environment env, Output out)
	throws Exception
    {
	boolean done = false;
	Object result = null;
	while (! done) {
	    if (atom(expr)) {
		result = expr;
		if ((! isPrimitive(expr)) &&
		    (expr instanceof String)) {
		    result = Environment.find((String)expr, env);
		}
		done = true;
	    } else {
		Object op = eval(Pair.car(expr), env, null);
		if (op.equals("quote")) {
		    result = Pair.cdr(expr);
		    done = true;
		} else if (op.equals("cond")) {
		    expr = evalCond(Pair.cdr(expr), env);
		} else if (op.equals("let")) {
		    env = evalLet(Pair.car(Pair.cdr(expr)), env);
		    expr = Pair.car(Pair.cdr(Pair.cdr(expr)));
		} else if (op.equals("fn")) {
		    result = evalFN(Pair.cdr(expr), env);
		    done = true;
		} else if ((op.equals("cons")) &&
			   (out != null)) {
		    out.send(eval(Pair.car(Pair.cdr(expr)), env, null));
		    expr = Pair.car(Pair.cdr(Pair.cdr(expr)));
		} else {
		    Object args = evalList(Pair.cdr(expr), env);
		    if (op instanceof Function) {
			expr = ((Function)op).getBody();
			env = ((Function)op).getNewEnvironment(args);
		    } else if ((op instanceof String) &&
			       isPrimitive(op)) {
			result = applyPrimitive((String)op, args);
			done = true;
		    } else {
			done = true;
		    }
		}
	    }
	}
	return result;
    }

    public static void main(String[] args) {
	BufferedReader in =
	    new BufferedReader(new InputStreamReader(System.in));
	/*
	try {
	    BufferedReader fileIn =
		new BufferedReader(new FileReader(args[0]));
	    PrintStream[] destinations = new PrintStream[1];
	    destinations[0] = System.out;
	    Output out = new Output(destinations);
	    Object programSource = read(fileIn.read(), fileIn);
	    // System.out.println(print(programSource));
	    Object program = eval(programSource,
				  Environment.emptyEnv, null);
	    Object result = null;
	    if (program instanceof Function) {
		Pair programArgs = Input.initialInput(null, in);
		result = ((Function)program).apply(programArgs, out);
	    }
	    out.sendAll(result);
	} catch (Exception e) {
	    System.err.println(e.getMessage());
	}
	*/

	Object sExpr = null;
	String exitStr = "exit";
	while (! exitStr.equals(sExpr)) {
	    System.out.print("expr> ");
	    try {
		sExpr = read(in.read(), in);
	        System.out.println(print(eval(sExpr,
					      Environment.emptyEnv, null)));
	    } catch (Exception e) {
		System.out.println(e.getMessage());
	    }
	}
    }
}
