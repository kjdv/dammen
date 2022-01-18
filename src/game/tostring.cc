/* game/tostring.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "game.ih"
#include <sstream>

string klaas::tostring(Move& move) {
    stringstream sstr;
    string       temp;
    string       ret;

    for(unsigned i = 0; i < move.priority(); ++i)
        sstr << move.field(i) + 1 << " ";
    sstr.seekp(0, ios::beg);
    sstr >> temp;
    ret = temp;
    for(unsigned i = 1; i < move.priority(); ++i) {
        sstr >> temp;
        ret += move.capture() ? " x " : " - ";
        ret += temp;
    }
    return ret;
}
