/* evaluator/tobepromoted.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"evaluator.ih"

int klaas::tobepromoted(Field *setup)
{
	int ret = 0;

	for(unsigned i = 5; i < 20; ++i)
		{
			if(setup[i].getstate() == WHITE)
				{
					if(setup[i].map().canr1() && setup[i].map().canr2())
						{
							if(setup[setup[i].map().fieldr1()].getstate() == EMPTY && setup[setup[i].map().fieldr2()].getstate() == EMPTY)
								switch(i / 5)
									{
									case 1:
										ret -= TBP_ROW1;
										break;
									case 2:
										ret -= TBP_ROW2;
										break;
									case 3:
										ret -= TBP_ROW3;
										break;
									default:
										break;
									}
						}
					else if(!setup[i].map().canr1() && setup[setup[i].map().fieldr2()].getstate() == EMPTY)
						switch(i / 5)
									{
									case 1:
										ret -= TBP_ROW1;
										break;
									case 2:
										ret -= TBP_ROW2;
										break;
									case 3:
										ret -= TBP_ROW3;
										break;
									default:
										break;
									}
					else if(!setup[i].map().canr2() && setup[setup[i].map().fieldr1()].getstate() == EMPTY)
						switch(i / 5)
									{
									case 1:
										ret -= TBP_ROW1;
										break;
									case 2:
										ret -= TBP_ROW2;
										break;
									case 3:
										ret -= TBP_ROW3;
										break;
									default:
										break;
									}
				}
		}

	for(unsigned i = 30; i < 45; ++i)
		{
			if(setup[i].getstate() == BLACK)
				{
					if(setup[i].map().canr3() && setup[i].map().canr4())
						{
							if(setup[setup[i].map().fieldr3()].getstate() == EMPTY && setup[setup[i].map().fieldr4()].getstate() == EMPTY)
								switch(i / 5)
									{
									case 6:
										ret += TBP_ROW3;
										break;
									case 7:
										ret += TBP_ROW2;
										break;
									case 8:
										ret += TBP_ROW1;
										break;
									default:
										break;
									}
						}
					else if(!setup[i].map().canr3() && setup[setup[i].map().fieldr4()].getstate() == EMPTY)
						switch(i / 5)
									{
									case 6:
										ret += TBP_ROW3;
										break;
									case 7:
										ret += TBP_ROW2;
										break;
									case 8:
										ret += TBP_ROW1;
										break;
									default:
										break;
									}
					else if(!setup[i].map().canr4() && setup[setup[i].map().fieldr3()].getstate() == EMPTY)
						switch(i / 5)
									{
									case 6:
										ret += TBP_ROW3;
										break;
									case 7:
										ret += TBP_ROW2;
										break;
									case 8:
										ret += TBP_ROW1;
										break;
									default:
										break;
									}
				}
		}
						
	return ret;
}

/* OLD:
#define TOBEPROMOTED_1 50
#define TOBEPROMOTED_2 150

int klaas::tobepromoted(Field *setup)
{
	int ret = 0;

	for(unsigned i = 0; i < 50; ++i)
		{
			if(i > 29 && setup[i].getstate() == BLACK)
				{
					if(setup[i].map().canr3(2))
						{
							if((setup[setup[i].map().fieldr3()].getstate() == EMPTY 
									&& setup[setup[i].map().fieldr3(2)].getstate() == EMPTY)
								 && setup[i + 10].getstate() == EMPTY)

								ret += TOBEPROMOTED_1;
							if(i > 34)
								ret += TOBEPROMOTED_1;
						}
					else if(setup[i].map().canr4(2))
						{
							if((setup[setup[i].map().fieldr4()].getstate() == EMPTY
									&& setup[setup[i].map().fieldr4(2)].getstate() == EMPTY)
								 && setup[i + 10].getstate() == EMPTY)

								ret += TOBEPROMOTED_1;
							if(i > 34)
								ret += TOBEPROMOTED_1;
						}
					else if(i > 39)
						{
							if(setup[i].map().canr3() && setup[setup[i].map().fieldr3()].getstate() == EMPTY)
								{
									if(!setup[i].map().canr4() || setup[setup[i].map().fieldr4()].getstate() == EMPTY)
										ret += TOBEPROMOTED_2;
								}
							else if(setup[i].map().canr4() && setup[setup[i].map().fieldr4()].getstate() == EMPTY)
								{
									if(!setup[i].map().canr3() || setup[setup[i].map().fieldr3()].getstate() == EMPTY)
										ret += TOBEPROMOTED_2;
								}
						}
				}
			if(i < 20 && setup[i].getstate() == WHITE)
				{
					if(setup[i].map().canr1(2))
						{
							if((setup[setup[i].map().fieldr1()].getstate() == EMPTY
									&& setup[setup[i].map().fieldr1(2)].getstate() == EMPTY)
								 && setup[i - 10].getstate() == EMPTY)

								ret -= TOBEPROMOTED_1;
							if(i < 15)
								ret -= TOBEPROMOTED_1;
						}
					else if(setup[i].map().canr2(2))
						{
							if((setup[setup[i].map().fieldr2()].getstate() == EMPTY
									&& setup[setup[i].map().fieldr2(2)].getstate() == EMPTY)
								 && setup[i - 10].getstate() == EMPTY)

								ret -= TOBEPROMOTED_1;
							if(i < 15)
								ret -= TOBEPROMOTED_1;
						}
					else if(i < 10)
						{
							if(setup[i].map().canr1() && setup[setup[i].map().fieldr1()].getstate() == EMPTY)
								{
									if(!setup[i].map().canr2() || setup[setup[i].map().fieldr2()].getstate() == EMPTY)
										ret -= TOBEPROMOTED_2;
								}
							else if(setup[i].map().canr2() && setup[setup[i].map().fieldr2()].getstate() == EMPTY)
								{
									if(!setup[i].map().canr1() || setup[setup[i].map().fieldr1()].getstate() == EMPTY)
										ret -= TOBEPROMOTED_2;
								}
						}
				}
		}

	return ret;
}

*/
