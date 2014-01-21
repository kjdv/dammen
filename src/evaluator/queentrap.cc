/* evaluator/queentrap.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"evaluator.ih"

int klaas::queentrap(Field *setup)
{
	int ret = 0;
	for(unsigned i = 0; i < 50; ++i)
		{
			if(setup[i].getstate() == WHITEQUEEN)
				{
					// r1
					if(!setup[i].map().canr1() || ally(setup[setup[i].map().fieldr1()], WHITEQUEEN))
						{
							if(setup[i].map().canr4(2) && (setup[setup[i].map().fieldr4()].getstate() == EMPTY &&
																						 ally(setup[setup[i].map().fieldr4(2)], WHITEQUEEN)))
								 ret -= TRAPVALUE;
						}
					// r2
					if(!setup[i].map().canr2() || ally(setup[setup[i].map().fieldr2()], WHITEQUEEN))
						{
							if(setup[i].map().canr3(2) && (setup[setup[i].map().fieldr3()].getstate() == EMPTY &&
																						 ally(setup[setup[i].map().fieldr3(2)], WHITEQUEEN)))
								 ret -= TRAPVALUE;
						}
					// r3
					if(!setup[i].map().canr3() || ally(setup[setup[i].map().fieldr3()], WHITEQUEEN))
						{
							if(setup[i].map().canr2(2) && (setup[setup[i].map().fieldr2()].getstate() == EMPTY &&
																						 ally(setup[setup[i].map().fieldr2(2)], WHITEQUEEN)))
								 ret -= TRAPVALUE;
						}
					// r4
					if(!setup[i].map().canr4() || ally(setup[setup[i].map().fieldr4()], WHITEQUEEN))
						{
							if(setup[i].map().canr1(2) && (setup[setup[i].map().fieldr1()].getstate() == EMPTY &&
																						 ally(setup[setup[i].map().fieldr1(2)], WHITEQUEEN)))
								ret -= TRAPVALUE;
						}
				}
			
			else if(setup[i].getstate() == BLACKQUEEN)
				{
					// r1
					if(!setup[i].map().canr1() || ally(setup[setup[i].map().fieldr1()], BLACKQUEEN))
						{
							if(setup[i].map().canr4(2) && (setup[setup[i].map().fieldr4()].getstate() == EMPTY &&
																						 ally(setup[setup[i].map().fieldr4(2)], BLACKQUEEN)))
								 ret += TRAPVALUE;
						}
					// r2
					if(!setup[i].map().canr2() || ally(setup[setup[i].map().fieldr2()], BLACKQUEEN))
						{
							if(setup[i].map().canr3(2) && (setup[setup[i].map().fieldr3()].getstate() == EMPTY &&
																						 ally(setup[setup[i].map().fieldr3(2)], BLACKQUEEN)))
								 ret += TRAPVALUE;
						}
					// r3
					if(!setup[i].map().canr3() || ally(setup[setup[i].map().fieldr3()], BLACKQUEEN))
						{
							if(setup[i].map().canr2(2) && (setup[setup[i].map().fieldr2()].getstate() == EMPTY &&
																						 ally(setup[setup[i].map().fieldr2(2)], BLACKQUEEN)))
								 ret += TRAPVALUE;
						}
					// r4
					if(!setup[i].map().canr4() || ally(setup[setup[i].map().fieldr4()], BLACKQUEEN))
						{
							if(setup[i].map().canr1(2) && (setup[setup[i].map().fieldr1()].getstate() == EMPTY &&
																						 ally(setup[setup[i].map().fieldr1(2)], BLACKQUEEN)))
								 ret += TRAPVALUE;
						}
				}
		}
	
	return ret;
}
