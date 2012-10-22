# Copyright (c) 2003 - 2006 by Omar Jarjur

# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

CC = gcc
LD = ld
CFLAGS = -m32 -w -I include -ffreestanding -c -pipe -DBARE_HARDWARE
LDFLAGS = -m elf_i386 -dN -Ttext 0x100000 -e start
NOLIB = -nostdlib -nostartfiles -nodefaultlibs -nostdinc -static

KERNELOBJS = include/boot.o include/console.o include/mem.o include/io.o main.o
CLEANOBJS = main.c main.o include/*.o bin/kImage 

bin/kImage: $(KERNELOBJS)
	$(LD) $(LDFLAGS) -o $@ $(KERNELOBJS)
	mbchk bin/kImage

main.o: main.c

main.c:
	./compile.sh -m kernel.lsk -g $@

.c.o:	include/console.c include/mem.c include/io.c main.c
	$(CC) $(CFLAGS) $(NOLIB) -o $@ $<
.S.o:	include/boot.S
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(CLEANOBJS)
