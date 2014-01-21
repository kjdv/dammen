/* evaluator/block.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"evaluator.ih"

unsigned blockhelper_white(Field *setup, unsigned i)
{
	unsigned ret = 0;
	if(setup[i].map().canr1() && enemy(setup[setup[i].map().fieldr1()], WHITE))
		++ret;
	if(setup[i].map().canr2() && enemy(setup[setup[i].map().fieldr2()], WHITE))
		++ret;
	
	if(i > 10)
		{
			if(enemy(setup[i - 10], WHITE))
				++ret;
			ret += blockhelper_white(setup, i - 10);
		}
	return ret;
}

unsigned blockhelper_black(Field *setup, unsigned i)
{
	unsigned ret = 0;
	if(setup[i].map().canr3() && enemy(setup[setup[i].map().fieldr3()], BLACK))
		++ret;
	if(setup[i].map().canr4() && enemy(setup[setup[i].map().fieldr4()], BLACK))
		++ret;
	
	if(i < 40)
		{
			if(enemy(setup[i + 10], BLACK))
				++ret;
			ret += blockhelper_black(setup, i + 10);
		}
	return ret;
}

int klaas::block(Field *setup)
{
	int ret = 0;
	for(unsigned i = 0; i < 50; ++i)
		{
			if(i < 30 && setup[i].getstate() == WHITE)
				{
					if(blockhelper_white(setup, i) < 2)
						ret -= i < 20 ? BLOCKVALUE_2 : BLOCKVALUE_1;
				}
			else if(i > 19 && setup[i].getstate() == BLACK)
				{
					if(blockhelper_black(setup, i) < 2)
						ret += i > 29 ? BLOCKVALUE_2 : BLOCKVALUE_1;
				}
		}

	return ret;
}
