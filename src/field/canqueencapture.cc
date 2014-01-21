/* field/canqueencapture.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* my apologies for the unreadability of this code -KJdV */

#include"field.ih"

bool Field::canqueencapture(Field *setup, Movelist &list, bool wit, bool first)
{
	bool ret = false;
  unsigned i = 1;
  unsigned j;
  unsigned org = list.index();

  if(d_state == BLACKQUEEN)
    wit = false;
  
  // r1
  while(d_map.canr1(i) && setup[d_map.fieldr1(i)].d_state == EMPTY) // skip all empty fields
    ++i;

	// removable enemy found?
  if((d_map.canr1(i + 1) && setup[d_map.fieldr1(i)].enemy(wit)) && (setup[d_map.fieldr1(i + 1)].d_state == EMPTY))
    {
			if(!first) // copy
				list.copy(org);
      else
				{
					list.add(d_number);
					list.capture();
				}
			setup[d_map.fieldr1(i)].d_lock = true; // lock the field
			
			j = i + 1;
      while(d_map.canr1(j) && setup[d_map.fieldr1(j)].d_state == EMPTY) // where can it land?
				{
					list.copy(org);
					list.add(d_map.fieldr1(j));
					setup[d_map.fieldr1(j)].canqueencapture(setup, list, wit, false); // recurse from other field
					++j;
				}
			list.increment(); // increment
			setup[d_map.fieldr1(i)].d_lock = false; // unlock the field
      ret = true;
		}
  i = 1; // reset i and continue for next direction
  
  // r2
  while(d_map.canr2(i) && setup[d_map.fieldr2(i)].d_state == EMPTY)
    ++i;
 
  if((d_map.canr2(i + 1) && setup[d_map.fieldr2(i)].enemy(wit)) && (setup[d_map.fieldr2(i + 1)].d_state == EMPTY))
    {
			if(!first)
				list.copy(org);
      else
				{
					list.add(d_number);
					list.capture();
				}
			setup[d_map.fieldr2(i)].d_lock = true;

      j = i + 1;
      while(d_map.canr2(j) && setup[d_map.fieldr2(j)].d_state == EMPTY)
				{
					list.copy(org);
					list.add(d_map.fieldr2(j));
					setup[d_map.fieldr2(j)].canqueencapture(setup, list, wit, false);
					++j;
				}
			list.increment();
			setup[d_map.fieldr2(i)].d_lock = false;
      ret = true;
		}
  i = 1;

  // r3
  while(d_map.canr3(i) && setup[d_map.fieldr3(i)].d_state == EMPTY)
    ++i;				
  
  if((d_map.canr3(i + 1) && setup[d_map.fieldr3(i)].enemy(wit)) && (setup[d_map.fieldr3(i + 1)].d_state == EMPTY))
    {
			if(!first)
				list.copy(org);
      else
				{
					list.add(d_number);
					list.capture();
				}
			setup[d_map.fieldr3(i)].d_lock = true;

			j = i + 1;
      while(d_map.canr3(j) && setup[d_map.fieldr3(j)].d_state == EMPTY)
				{
					list.copy(org);
					list.add(d_map.fieldr3(j));
					setup[d_map.fieldr3(j)].canqueencapture(setup, list, wit, false);
					++j;
				}
			list.increment();
			setup[d_map.fieldr3(i)].d_lock = false;
      ret = true;
		}
  i = 1;

	// r4
  while(d_map.canr4(i) && setup[d_map.fieldr4(i)].d_state == EMPTY)
    ++i;

	if((d_map.canr4(i + 1) && setup[d_map.fieldr4(i)].enemy(wit)) && (setup[d_map.fieldr4(i + 1)].d_state == EMPTY))
    {
			if(!first)
				list.copy(org);
      else
				{
					list.add(d_number);
					list.capture();
				}
			setup[d_map.fieldr4(i)].d_lock = true;
			j = i + 1;
      while(d_map.canr4(j) && setup[d_map.fieldr4(j)].d_state == EMPTY)
				{
					list.copy(org);
					list.add(d_map.fieldr4(j));
					setup[d_map.fieldr4(j)].canqueencapture(setup, list, wit, false);
					++j;
				}
			list.increment();
			setup[d_map.fieldr4(i)].d_lock = false;
      ret = true;
		}

	return ret;
}
