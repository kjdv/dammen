/* evaluator/balanced.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"evaluator.ih"

int klaas::balanced(Field *setup)
{
	int ret = 0;
	int count = 0;

	unsigned i = 0;
	while(i < 47) // left flank
		{
			switch(setup[i].getstate())
				{
				case BLACK:
					++count;
					break;
				case WHITE:
					--count;
					break;
				default:
					break;
				}
			
			switch(i % 10)
				{
				case 0:
					i += 5;
					break;
				case 6:
					i += 4;
					break;
				default:
					++i;
				}
		}
	if(count > 0)
		ret += UNBALANCED_PENALTY * count;
	else if(count < 0)
		ret += UNBALANCED_PENALTY * count;
	

	count = 0;
	i = 3;
	while(i < 50) // right flank
		{
			switch(setup[i].getstate())
				{
				case BLACK:
					++count;
					break;
				case WHITE:
					--count;
					break;
				default:
					break;
				}

			switch(i % 10)
				{
				case 4:
					i += 5;
					break;
				case 9:
					i += 4;
					break;
				default:
					++i;
				}
		}
	if(count > 0)
		{
			if(count > 2)
				count = 2;
			ret += UNBALANCED_PENALTY * count;
		}
	else if(count < 0)
		{
			if(count < -2)
				count = -2;
			ret += UNBALANCED_PENALTY * count;
		}

	return ret;
}
