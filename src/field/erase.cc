/* field/erase.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"field.ih"

void Field::erase(Field *setup, unsigned target)
{
	unsigned i = 1;
	switch(giver(d_number, target))
		{
		case 1:
			while(d_map.fieldr1(i) != target)
				{
					setup[d_map.fieldr1(i)].setstate(EMPTY);
					++i;
				}
			break;
		case 2:
			while(d_map.fieldr2(i) != target)
				{
					setup[d_map.fieldr2(i)].setstate(EMPTY);
					++i;
				}
			break;
		case 3:
			while(d_map.fieldr3(i) != target)
				{
					setup[d_map.fieldr3(i)].setstate(EMPTY);
					++i;
				}
			break;
		case 4:
			while(d_map.fieldr4(i) != target)
				{
					setup[d_map.fieldr4(i)].setstate(EMPTY);
					++i;
				}
		}
}
