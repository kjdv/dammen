/* evaluator/central.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "evaluator.ih"

int klaas::central(Field* setup) {
    int      ret = 0;
    unsigned i   = 11;
    while(i < 39) {
        switch(setup[i].getstate()) {
        case WHITE:
            ret -= CENTRAL;
            if((i > 15 && i < 35)) {
                if(i % 10 != 3 && i % 10 != 6)
                    ret -= CENTRAL;
            }
            break;
        case BLACK:
            ret += CENTRAL;
            if((i > 15 && i < 35)) {
                if(i % 10 != 3 && i % 10 != 6)
                    ret += CENTRAL;
            }
            break;
        default:
            break;
        }

        switch(i % 10) {
        case 3:
            i += 3;
            break;
        case 8:
            i += 3;
            break;
        default:
            ++i;
        }
    }
    return ret;
}
