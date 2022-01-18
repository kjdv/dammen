/* move/fixate.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "move.ih"

void Movelist::fixate() {
    unsigned max         = 0;
    bool     mustcapture = false;
    for(unsigned i = 0; i < d_index; ++i) // check if d_capture in the moves is set and how many pieces to be removed
    {
        if(d_mlist[i].priority() >= max) {
            max = d_mlist[i].priority();
            if(d_mlist[i].capture() == true)
                mustcapture = true;
        }
    }

    d_nallowed = 0;
    for(unsigned i = 0; i < d_index; ++i) // which moves conform to the previously set conditions
    {
        if(d_mlist[i].priority() == max) {
            if(mustcapture) {
                if(d_mlist[i].capture() == true)
                    d_allowed[d_nallowed++] = i;
            } else
                d_allowed[d_nallowed++] = i;
        }
    }
}
