# Copyright (c) 2012 by Omar Jarjur

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

BINOBJS = bin/desugar bin/standard-library bin/symbol-table bin/cps-transform bin/multitask bin/lambda-lift bin/compiler bin/codegen

$(BINOBJS):
	./bootstrap.sh

clean:
	rm -rf bin/

tests: $(BINOBJS)
	tests/runall.sh

install: $(BINOBJS)
	if [ ! -d "/usr/local/losak" ]; then mkdir /usr/local/losak; fi
	cp -r ./* /usr/local/losak/.
	sed -e "s/INSTALL_DIR=\"\.\"/INSTALL_DIR=\"\/usr\/local\/losak\"/" compile.sh > /usr/local/bin/losakc
	chmod ugo+rx /usr/local/bin/losakc

bin/kImage: $(BINOBJS)
	./compile.sh -bm kernel.lsk -o $@
	mbchk $@
