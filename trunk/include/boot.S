/* boot.S: Boots the kernel */
/* Copyright (c) 2004, 2005 by Omar Jarjur

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

.text
.globl start

.set STACK, 0x8000		/* 32k, as global definitions all become
                                   stack addresses. */
.set MAGIC, 0x1BADB002		/* Multiboot spec. magic number */
.set FLAGS, 0x00000003		/* Flags: Align modules and
                                          send memory info */
.align 4
header:
  .long MAGIC
  .long FLAGS
  .long -(MAGIC + FLAGS)

.comm stack, STACK

start:
  cli
  mov $(stack+STACK), %esp
  push %ebx
  push %eax
  call main
