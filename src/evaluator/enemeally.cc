/* evaluator/enemyally.hh
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"evaluator.ih"

bool klaas::enemy(Field &other, state self) // helper function
{
	switch(self)
		{
		case WHITE:
		case WHITEQUEEN:
			if(other.getstate() == BLACK || other.getstate() == BLACKQUEEN)
				return true;
			return false;
		case BLACK:
		case BLACKQUEEN:
			if(other.getstate() == WHITE || other.getstate() == WHITEQUEEN)
				return true;
			return false;
		default:
			return false;
		}
	return false;
}

bool klaas::ally(Field &other, state self) // analogous to enemy()
{
	switch(self)
		{
		case WHITE:
		case WHITEQUEEN:
			if(other.getstate() == WHITE || other.getstate() == WHITEQUEEN)
				return true;
			return false;
		case BLACK:
		case BLACKQUEEN:
			if(other.getstate() == BLACK || other.getstate() == BLACKQUEEN)
				return true;
			return false;
		default:
			return false;
		}
	return false;
}
