/* game/moveresolver.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */
#include "game.ih"
#include <chrono>
#include <iostream>

static double   s_total  = 0;
static unsigned s_number = 0;

void Game::moveresolver() {
    auto before = std::chrono::system_clock::now();

    unsigned count  = 0; // number of matching moves
    unsigned number = 0; // the number of the matching move

    for(unsigned i = 0; i < d_factory.npossible(); ++i) {
        if(d_clicks.field(0) == d_factory.move(i).field(0)) {
            unsigned index = 1; // index in d_factory.move(i)
            bool     match = true;
            for(unsigned j = 1; j < d_clicks.priority(); ++j) {
                for(unsigned k = index; k < d_factory.move(i).priority(); ++k) {
                    if(d_factory.move(i).field(k) == d_clicks.field(j)) {
                        index = k;
                        break;
                    }
                    if(k + 1 == d_factory.move(i).priority())
                        match = false;
                }
            }

            if(match) {
                ++count;
                number = i;
                if(count > 1) // no unique match
                    return;
            }
        }
    }

    if(count) // do the move, already checked for count > 1
    {
        d_clicks = d_factory.move(number);
        move();
    }

    auto after    = std::chrono::system_clock::now();
    auto duration = after - before;

    s_number += 1;
    s_total += duration.count();

    if(number % 1000 == 0) {
        std::cout << "average " << s_total / s_number << "ns\n";
    }
}
