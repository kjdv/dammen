/* evaluator/lock.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* Try to avoid these situations (two white pieces 'locking' three black pieces):
 * 
 * .x.x.    .x.x.
 * o.x.o or  .x.
 * . . .    .o.o.
 *
 * while this is good:
 *
 * |x.
 * |.o
 *
 */

#include"evaluator.ih"

int klaas::lock(Field *setup)
{
	int ret = 0;

	for(unsigned i = 0; i < 50; ++i)
		{
			if(setup[i].getstate() == BLACK)
				{
					if(setup[i].map().canr3() && setup[setup[i].map().fieldr3()].getstate() == WHITE)
						{
							if(setup[i].map().canr4())
								{
									if(setup[setup[i].map().fieldr4()].getstate() == WHITE)
										ret -= LOCKVALUE;
								}
							else
								ret += LOCKVALUE;
						}
					else if((!setup[i].map().canr3() && setup[i].map().canr4())
									&& setup[setup[i].map().fieldr4()].getstate() == WHITE)
						ret += LOCKVALUE;
				}
			else if(setup[i].getstate() == WHITE)
				{
					if(setup[i].map().canr1() && setup[setup[i].map().fieldr1()].getstate() == BLACK)
						{
							if(setup[i].map().canr2())
								{
									if(setup[setup[i].map().fieldr2()].getstate() == BLACK)
										ret += LOCKVALUE;
								}
							else
								ret -= LOCKVALUE;
						}
					else if((!setup[i].map().canr1() && setup[i].map().canr2())
									&& setup[setup[i].map().fieldr2()].getstate() == BLACK)
						ret -= LOCKVALUE;
				}
		}

	return ret;
}
