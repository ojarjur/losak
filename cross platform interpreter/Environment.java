/**
 * Environment.java
 * Class to represent a binding environment.
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
 * @version 1.0
 */
class Environment {
    private String var;
    private Object val;
    private Environment rest;

    public static Environment emptyEnv = null;

    /**
     * Find the value assigned to a variable in the given environment
     *
     * @param var The variable to be looked up.
     * @param env The environment in which to look up the variable.
     */
    public static Object find(String var, Environment env) {
	if (env == null) {
	    return null;
	} else if (var.equals(env.var)) {
	    return env.val;
	} else {
	    return find(var, env.rest);
	}
    }

    /**
     * Binds a variable to a value within a given environment.
     *
     * @param var The variable to be bound
     * @param val The value to be assigned to the variable
     * @param env The binding environment to be updated
     */
    public static Environment bind(Object var, Object val, Environment env) {
	if ((var != null) && (var instanceof String)) {
	    Environment result = new Environment();
	    result.var = (String)var;
	    result.val = val;
	    result.rest = env;
	    return result;
	} else if (var instanceof Pair) {
	    return bind(Pair.car(var), Pair.car(val),
			bind(Pair.cdr(var), Pair.cdr(val), env));
	}
	return env;
    }

    /**
     * Compare to environments to see if they are the same.
     *
     * @param env The environment to compare against.
     */
    public boolean equals(Object env) {
	if (env instanceof Environment) {
	    return ((var.equals(((Environment)env).var)) &&
		    (val.equals(((Environment)env).val)) &&
		    (rest.equals(((Environment)env).rest)));
	} else {
	    return false;
	}
    }
}
