/* evaluator/orphan.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"evaluator.ih"

int klaas::orphan(Field *setup)
{
	int ret = 0;

	for(unsigned i = 15; i < 36; ++i)
		{
			if(setup[i].getstate() == BLACK)
				{
					if(setup[i].map().canr1(2))
						{
							if((setup[setup[i].map().fieldr1()].getstate() == EMPTY
									&& setup[setup[i].map().fieldr1(2)].getstate() == EMPTY)
								 && setup[i - 10].getstate() == EMPTY)
								
								ret -= ORPHAN;
						}
					else if(setup[i].map().canr1())
						{
							if(setup[setup[i].map().fieldr1()].getstate() == EMPTY 
								 && setup[i - 10].getstate() == EMPTY)

								ret -= ORPHAN;
						}

					if(setup[i].map().canr2(2))
						{
							if((setup[setup[i].map().fieldr2()].getstate() == EMPTY 
									&& setup[setup[i].map().fieldr2(2)].getstate() == EMPTY) 
								 && setup[i - 10].getstate() == EMPTY)

								ret -= ORPHAN;
						}
					else if(setup[i].map().canr2())
						{
							if(setup[setup[i].map().fieldr2()].getstate() == EMPTY
								 && setup[i - 10].getstate() == EMPTY)
								
								ret -= ORPHAN;
						}
				}
			else if(setup[i].getstate() == WHITE)
				{
					if(setup[i].map().canr3(2))
						{
							if((setup[setup[i].map().fieldr3()].getstate() == EMPTY
									&& setup[setup[i].map().fieldr3(2)].getstate() == EMPTY)
								 && setup[i + 10].getstate() == EMPTY)
								
								ret += ORPHAN;
						}
					else if(setup[i].map().canr3())
						{
							if(setup[setup[i].map().fieldr3()].getstate() == EMPTY 
								 && setup[i + 10].getstate() == EMPTY)
								
								ret += ORPHAN;
						}

					if(setup[i].map().canr4(2))
						{
							if((setup[setup[i].map().fieldr4()].getstate() == EMPTY
									&& setup[setup[i].map().fieldr4(2)].getstate() == EMPTY)
								 && setup[i + 10].getstate() == EMPTY)
								
								ret += ORPHAN;
						}
					else if(setup[i].map().canr4())
						{
							if(setup[setup[i].map().fieldr4()].getstate() == EMPTY
								 && setup[i + 10].getstate() == EMPTY)
								
								ret += ORPHAN;
						}
				}
		}
	return ret;
}
