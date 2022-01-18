/* setup/setup.hh
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* class for the stup of the board, that is, how the pieces are arranged
 * class voor de setup op het bord
 *
 */

#ifndef _SETUP_HH_
#define _SETUP_HH_
#include "../field/field.hh"

namespace klaas {
class Setup {
  public:                 // quick & dirty, everything is public. Not elegant, but convinient
    Field*   d_setup;     // the fields
    bool     d_whitemove; // whose turn is it?
    bool     d_capture;   // is this a capture
    Movelist d_factory;   // to save all possible moves

    void move(unsigned index);                 // do the index'th possible move
    void moveai(Setup& other, unsigned index); // the same, but uses another Setup's d_factory. use with care!

    Setup();
    ~Setup() {
        delete[] d_setup;
    }
    void operator=(Setup const& other);

    void init();

    state getstate(unsigned field) {
        return d_setup[field - 1].getstate();
    }

    void findmoves(); // find all possible moves
};
} // namespace klaas

#endif
