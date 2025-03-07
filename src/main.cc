/* main.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "board/board.hh"
#include <ctime>
#include <gtkmm/main.h>

using namespace std;
using namespace Gtk;
using namespace klaas;

int main(int argc, char** argv) {
    srand(time(NULL));
    Main  kit(argc, argv);
    Board board;
    Main::run(board);
    return 0;
}
