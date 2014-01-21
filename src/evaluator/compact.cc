/* evaluator/compact.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"evaluator.ih"

int klaas::compact(Field *setup)
{
	int ret = 0;

	for(unsigned i = 10; i < 40; ++i)
		{
			if(i % 10 != 4 && i % 10 != 5) // skip boundary pieces
				{
					switch(setup[i].getstate())
						{
						case WHITE:
							if(setup[setup[i].map().fieldr3()].getstate() == WHITE)
								ret -= COMPACT;
							if(setup[setup[i].map().fieldr4()].getstate() == WHITE)
								ret -= COMPACT;
							break;
						case BLACK:
							if(setup[setup[i].map().fieldr1()].getstate() == BLACK)
								ret += COMPACT;
							if(setup[setup[i].map().fieldr2()].getstate() == BLACK)
								ret += COMPACT;
							break;
						default:
							break;
						}
				}
		}
	return ret;
}
