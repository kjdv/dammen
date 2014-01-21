/* evaluator/endgame.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"evaluator.ih"
#include<cstdlib>

int klaas::endgame(Field *setup)
{
	int ret = countpieces(setup);
	ret += compact(setup);
	ret += lock(setup);
	ret += tobepromoted(setup);
	ret += queentrap(setup);
	ret += block(setup);

	ret += static_cast<int>(RANDOM_ELEMENT * (static_cast<double>(rand()) / RAND_MAX - 0.5)); // random element for varition

	return ret;
}
