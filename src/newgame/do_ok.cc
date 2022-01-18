/* newgame/do_ok.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "newgame.ih"

void Newgame::do_ok() {
    if(d_d1.get_active())
        d_diff = 1;
    else if(d_d2.get_active())
        d_diff = 2;
    else if(d_d3.get_active())
        d_diff = 3;
    else
        d_diff = 0;
    hide();
}
