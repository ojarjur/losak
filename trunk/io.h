/* io.h: Input/Output operations. */
/* Copyright (c) 2004 - 2007 by Omar Jarjur

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

#ifndef IO_H
#define IO_H
#include "mem.h"

#define ERR_NO_OS 0
#define ERR_BAD_BOOT 1
#define ERR_MEM_LIMIT 2
#define ERR_UNKNOWN 3
#define ERR_INTERNAL 4

void init_io();
pointer get_input();
void execute(pointer output);
void error(int type);

#ifdef BARE_HARDWARE
void halt();
void reboot();
#endif

#endif
