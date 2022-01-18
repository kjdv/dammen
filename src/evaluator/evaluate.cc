/* evaluator/evaluator.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "evaluator.ih"
#include <cstdlib>

int klaas::evaluate(Field* setup) {
    // is this the endgame?
    int ret = 0;
    for(unsigned i = 0; i < 50; ++i) {
        if(setup[i].getstate() != EMPTY)
            ++ret;
    }
    if(ret <= 20)
        return endgame(setup);

    ret = countpieces(setup);
    ret += orphan(setup);
    ret += tobepromoted(setup);
    ret += block(setup);

    ret += compact(setup);
    ret += central(setup);
    ret += boundary(setup);
    ret += behind(setup);
    ret += balanced(setup);
    ret += lock(setup);
    ret += toofar(setup);

    ret += static_cast<int>(RANDOM_ELEMENT * (static_cast<double>(rand()) / RAND_MAX - 0.5)); // random element for varition
    return ret;
}
