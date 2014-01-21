/* field/cancapture.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* recursive for multiple captures */

#include"field.ih"

bool Field::cancapture(Field *setup, Movelist &list, bool wit, bool first)
{
	bool ret = false;
  unsigned org = list.index();
  if(d_state == BLACK)
    wit = false;
  
  // r1
  if((d_map.canr1(2) && setup[d_map.fieldr1()].enemy(wit)) && (setup[d_map.fieldr1(2)].d_state == EMPTY))
    {
      if(!first)
				list.copy(org);
      else
				{
					list.add(d_number);
					list.capture();
				}
      list.add(d_map.fieldr1(2));
      setup[d_map.fieldr1()].d_lock = true; // lock the field
      setup[d_map.fieldr1(2)].cancapture(setup, list, wit, false); // recurse from other field
      setup[d_map.fieldr1()].d_lock = false; // unlock the field
      list.increment();
      ret = true;
    }
  
  // r2
  if((d_map.canr2(2) && setup[d_map.fieldr2()].enemy(wit)) && (setup[d_map.fieldr2(2)].d_state == EMPTY))
    {
      if(!first)
				list.copy(org);
      else
				{
					list.add(d_number);
					list.capture();
				}
      list.add(d_map.fieldr2(2));
      setup[d_map.fieldr2()].d_lock = true;
      setup[d_map.fieldr2(2)].cancapture(setup, list, wit, false);
      setup[d_map.fieldr2()].d_lock = false;
      list.increment();
      ret = true;
    }
  
  // r3
  if((d_map.canr3(2) && setup[d_map.fieldr3()].enemy(wit)) && (d_map.fieldr3(2) && setup[d_map.fieldr3(2)].d_state == EMPTY))
    {
      if(!first)
				list.copy(org);
      else
				{
					list.add(d_number);
					list.capture();
				}
      list.add(d_map.fieldr3(2));
      setup[d_map.fieldr3()].d_lock = true;
      setup[d_map.fieldr3(2)].cancapture(setup, list, wit, false);
      setup[d_map.fieldr3()].d_lock = false;
      list.increment();
      ret = true;
    }
  
  // r4
  if((d_map.canr4(2) && setup[d_map.fieldr4()].enemy(wit)) && (setup[d_map.fieldr4(2)].d_state == EMPTY))
    {
      if(!first)
				list.copy(org);
      else
				{
					list.add(d_number);
					list.capture();
				}
      list.add(d_map.fieldr4(2));
      setup[d_map.fieldr4()].d_lock = true;
      setup[d_map.fieldr4(2)].cancapture(setup, list, wit, false);
      setup[d_map.fieldr4()].d_lock = false;
      list.increment();
      ret = true;
    }
  
  return ret;
}
