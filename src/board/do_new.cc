/* board/do_new.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/*
 * This happens if you press the 'New' Button.
 *
 */
#include "../newgame/newgame.hh"
#include "board.ih"
#include <gtkmm/main.h>

void Board::do_new() {
    Newgame dialog;
    dialog.run();
    unsigned d = dialog.d_diff;
    switch(d) {
    case 1:
        d_game.init(EASY);
        break;
    case 2:
        d_game.init(NORMAL);
        break;
    case 3:
        d_game.init(HARD);
        break;
    default:
        break;
    }

    // redraw everything
    this->queue_draw();

    while(Main::events_pending())
        Main::iteration();
}
