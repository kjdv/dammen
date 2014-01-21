/* field/canmove.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"field.ih"

void Field::canmove(Field *setup, Movelist &list)
{
	if(d_state == WHITE)
		{
			if(d_map.canr1() && setup[d_map.fieldr1()].d_state == EMPTY)
				{
					list.add(d_number);
					list.add(d_map.fieldr1());
					list.increment();
				}
			if(d_map.canr2() && setup[d_map.fieldr2()].d_state == EMPTY)
				{
					list.add(d_number);
					list.add(d_map.fieldr2());
					list.increment();
				}
		}
	else if(d_state == BLACK)
		{
			if(d_map.canr3() && setup[d_map.fieldr3()].d_state == EMPTY)
				{
					list.add(d_number);
					list.add(d_map.fieldr3());
					list.increment();
				}
			if(d_map.canr4() && setup[d_map.fieldr4()].d_state == EMPTY)
				{
					list.add(d_number);
					list.add(d_map.fieldr4());
					list.increment();
				}
		}
}
