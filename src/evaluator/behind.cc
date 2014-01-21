/* evaluator/behind.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"evaluator.ih"

int klaas::behind(Field *setup)
{
	int ret = 0;

	// BLACK
	if(setup[0].getstate() == BLACK)
		ret -= CORNER;

	if(setup[1].getstate() == BLACK)
		{
			ret += SUBMIDDLE_1;
			if(setup[6].getstate() == BLACK)
				ret += SUBMIDDLE_2;
			if(setup[7].getstate() == BLACK)
				ret += SUBMIDDLE_2;
		}

	if(setup[2].getstate() == BLACK)
		{
			ret += MIDDLE_1;
			if(setup[6].getstate() == BLACK)
				ret += MIDDLE_2;
			if(setup[7].getstate() == BLACK)
				ret += MIDDLE_2;
		}	

	if(setup[3].getstate() == BLACK)
		{
			ret += SUBMIDDLE_1;
			if(setup[8].getstate() == BLACK)
				ret += SUBMIDDLE_2;
			if(setup[9].getstate() == BLACK)
				ret += SUBMIDDLE_2;
		}

	if(setup[4].getstate() == BLACK)
		ret -= CORNER;
	

	// WHITE
	if(setup[45].getstate() == WHITE)
		ret += CORNER;

	if(setup[46].getstate() == WHITE)
		{
			ret -= SUBMIDDLE_1;
			if(setup[41].getstate() == WHITE)
				ret -= SUBMIDDLE_2;
			if(setup[42].getstate() == WHITE)
				ret -= SUBMIDDLE_2;
		}

	if(setup[47].getstate() == WHITE)
		{
			ret -= MIDDLE_1;
			if(setup[42].getstate() == WHITE)
				ret -= MIDDLE_2;
			if(setup[43].getstate() == WHITE)
				ret -= MIDDLE_2;
		}	

	if(setup[48].getstate() == WHITE)
		{
			ret -= SUBMIDDLE_1;
			if(setup[43].getstate() == WHITE)
				ret -= SUBMIDDLE_2;
			if(setup[44].getstate() == WHITE)
				ret -= SUBMIDDLE_2;
		}

	if(setup[49].getstate() == WHITE)
		ret += CORNER;

	return ret;
}
