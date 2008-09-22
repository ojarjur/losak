/* eval.h: Eval primitives. */
/* Copyright (c) 2004 - 2006 by Omar Jarjur

This program is free software; you can redistribute it and/or
modify it under the terms of version 2 of the GNU General
Public License as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifndef EVAL_H
#define EVAL_H
#include "mem.h"

pointer val, args, stack, temp, true, env, call_stack;
int sign_mask;
function_addr return_location;

void init_eval();
void nil_function();
int length(pointer list);
pointer eval_primitive(pointer op, pointer params);
void top_level();
void end_function();

#endif
