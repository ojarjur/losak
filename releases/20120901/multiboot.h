/* multiboot.h: Multiboot data structures.
 * See the multiboot documentation for more
 * details of the multiboot specification.
 * http://www.gnu.org/software/grub/manual/multiboot/multiboot.html
 */
/* Copyright (c) 2004, 2006 by Omar Jarjur

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

#define BOOT_MAGIC 0x2badb002

typedef struct {
  unsigned long flags;
  unsigned long mem_lower;
  unsigned long mem_upper;
  unsigned long boot_device; /* I don't actually use this. To get the
			      *	root device, just parse the command line.
			      */
  unsigned long cmd_line;
  unsigned long mods_count;
  unsigned long mods_addr;
  /**
   * An unimaginable amount of extra stuff goes here,
   * but we won't use it.
   */
} multiboot_data;

int getFlag (unsigned long flags, int pos) {
  return (flags & (1<<pos));
}
