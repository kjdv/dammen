/* board/do_save.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* Saves the game */

#include "board.ih"
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/stock.h>

void Board::do_save() {
    FileChooserDialog dialog("Save Game As:", FILE_CHOOSER_ACTION_SAVE);

    dialog.add_button(Stock::CANCEL, RESPONSE_CANCEL);
    dialog.add_button(Stock::SAVE, RESPONSE_OK);

    int    res = dialog.run();
    string file;
    switch(res) {
    case RESPONSE_OK:
        file = dialog.get_filename();
        d_game.writelog(file);
        break;
    case RESPONSE_CANCEL:
        break;
    default:
        break;
    }
}
