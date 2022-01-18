/* game/move.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "game.ih"

bool Game::move() {
    for(unsigned i = 0; i < d_factory.npossible(); ++i) {
        if(d_clicks == d_factory.move(i)) // check the move
        {
            log();
            Setup::move(i);

            d_msg = (d_whitemove ? "Black plays " : "White plays ");
            d_msg += tostring(d_clicks);
            d_msg += ". ";

            // for testing/debugging:
            // printstatus(d_setup);

            if(d_factory.npossible() == 0) {
                d_msg += d_whitemove ? "Black" : "White";
                d_msg += " has won!";
            } else {
                d_msg += d_whitemove ? "White's" : "Black's";
                d_msg += " turn.";
                if(!d_whitemove)
                    d_msg += " (computer thinks)";
            }

            if(!d_whitemove)
                ++d_counter;

            d_clicks.flush();
            return true;
        }
    }
    // move not found, so illegal
    d_clicks.flush();
    return false;
}
