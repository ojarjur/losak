/**
 * Function.java
 * Class to represent a Lisp function.
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
 */
class Function {
    private Environment env;
    private Object parameters, body;

    public Function(Object parameters, Object body, Environment env) {
	this.parameters = parameters;
	this.body = body;
	this.env = env;
    }

    public Environment getNewEnvironment(Object args) {
	return Environment.bind(parameters, args, env);
    }
    public Object getBody() {
	return body;
    }
    public Object apply(Object args, Output out) throws Exception
    {
	Environment env = getNewEnvironment(args);
	return MiniLosak.eval(body, env, out);
    }
}
