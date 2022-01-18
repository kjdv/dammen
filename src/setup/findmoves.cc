/* setup/findmoves.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "setup.ih"

void Setup::findmoves() {
    d_factory.flush(); // delete the previously found moves
    d_capture = false;

    for(unsigned i = 0; i < 50; ++i) {
        if(d_whitemove && d_setup[i].getstate() == WHITE) // is this a white piece
        {
            if(!d_capture) // if d_capture is already true, finding normal moves is not necesarry
            {
                if(!(d_capture = d_setup[i].cancapture(d_setup, d_factory, true)))
                    d_setup[i].canmove(d_setup, d_factory);
            } else
                d_setup[i].cancapture(d_setup, d_factory, true);
        } else if(!d_whitemove && d_setup[i].getstate() == BLACK) // same for a black piece
        {
            if(!d_capture) {
                if(!(d_capture = d_setup[i].cancapture(d_setup, d_factory, false)))
                    d_setup[i].canmove(d_setup, d_factory);
            } else
                d_setup[i].cancapture(d_setup, d_factory, false);
        } else if(d_whitemove && d_setup[i].getstate() == WHITEQUEEN) // white queen
        {
            if(!d_capture) {
                if(!(d_capture = d_setup[i].canqueencapture(d_setup, d_factory, true)))
                    d_setup[i].canqueenmove(d_setup, d_factory);
            } else
                d_setup[i].canqueencapture(d_setup, d_factory, true);
        } else if(!d_whitemove && d_setup[i].getstate() == BLACKQUEEN) // black queen
        {
            if(!d_capture) {
                if(!(d_capture = d_setup[i].canqueencapture(d_setup, d_factory, false)))
                    d_setup[i].canqueenmove(d_setup, d_factory);
            } else
                d_setup[i].canqueencapture(d_setup, d_factory, false);
        }
    }
    d_factory.fixate(); // which of the fount moves are legal?
}
