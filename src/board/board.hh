/* board/board.hh
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/*
 * The GTK interface's main window for the program.
 *
 */

#ifndef _BOARD_HH_
#define _BOARD_HH_
#include "../blacksquare/blacksquare.hh"
#include "../whitesquare/whitesquare.hh"
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/table.h>
#include <gtkmm/window.h>

namespace klaas {
class Board : public Gtk::Window {
    Game d_game; // The game on the board
  public:
    Board();
    ~Board() {
        delete[] d_blacksquares;
        delete[] d_whitesquares;
    }

  protected:
    Gtk::VBox    d_top, d_menu, d_bord, d_msg;
    Gtk::HBox    d_buttons;
    Gtk::Label   d_label;
    Gtk::Table   d_table;
    Blacksquare* d_blacksquares; // black fields
    Whitesquare* d_whitesquares; // white fields
    Gtk::Button  d_new, d_open, d_save, d_quit;

    // to do when buttons are clicked
    void do_new();
    void do_open();
    void do_save();
    void do_quit();
};
} // namespace klaas

#endif
