/* evaluator/countpieces.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

/* bluntly count all pieces */

#include "evaluator.ih"

int klaas::countpieces(Field* setup) {
    int ret = 0;
    for(unsigned i = 0; i < 50; ++i) {
        switch(setup[i].getstate()) {
        case WHITE:
            ret -= PIECEVALUE;
            break;
        case BLACK:
            ret += PIECEVALUE;
            break;
        case WHITEQUEEN:
            ret -= QUEENVALUE;
            break;
        case BLACKQUEEN:
            ret += QUEENVALUE;
            break;
        default:
            break;
        }
    }
    return ret;
}
