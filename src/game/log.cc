/* game/log.cc
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

void Game::log() {
    if(d_whitemove) {
        stringstream s;
        s << d_counter;
        string temp;
        s >> temp;
        d_log += temp;
        d_log += ": ";
    } else
        d_log += " ; ";
    d_log += tostring(d_clicks);

    if(!d_whitemove)
        d_log += "\n";
}
