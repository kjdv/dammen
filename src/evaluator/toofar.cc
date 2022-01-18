/* evaluator/toofar.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "evaluator.ih"

int klaas::toofar(Field* setup) {
    int ret = 0;

    // white:
    for(unsigned i = 10; i < 25; ++i) {
        if(setup[i].getstate() == WHITE) {
            switch(i % 10) {
            case 4:
                break;
            case 5:
                break;
            default:
                ret += TOOFAR;
            }
        }
    }

    // black
    for(unsigned i = 25; i < 40; ++i) {
        if(setup[i].getstate() == BLACK) {
            switch(i % 10) {
            case 4:
                break;
            case 5:
                break;
            default:
                ret -= TOOFAR;
            }
        }
    }

    return ret;
}
