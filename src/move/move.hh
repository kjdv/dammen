/* move/move.hh
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* class to save all possible moves */

#ifndef _MOVE_HH_
#define _MOVE_HH_
#include <vector>

namespace klaas {
class Move // a single move
{
    std::vector<unsigned> d_list; // the fields passed in the move
    unsigned              d_size;
    bool                  d_capture; // is this a capture?

  public:
    Move()
      : d_list(3)
      , d_size(0)
      , d_capture(false) {}

    bool operator==(Move const& other);
    void operator=(Move const& other);

    unsigned priority() // how many fields are passed? That is, implicit, how many pieces to be removed
    {
        return d_size;
    }
    unsigned field(unsigned index) // the indexth field
    {
        return d_list[index];
    }
    void flush();             // reset
    void add(unsigned field); // add a field
    void setcapture() {
        d_capture = true;
    }
    bool capture() {
        return d_capture;
    }
};

class Movelist // list of all moves
{
    std::vector<Move>     d_mlist;    // moves
    std::vector<unsigned> d_allowed;  // indices of allowed moves
    unsigned              d_index;    // how many moves (the index of the next to be inserted
    unsigned              d_nallowed; // how many allowed moves

  public:
    Movelist()
      : d_mlist(32)
      , d_allowed(32)
      , d_index(0)
      , d_nallowed(0) {}

    unsigned npossible() {
        return d_nallowed;
    }
    void fixate(); // find the allowed moves in d_mlist
    void flush();  // reset

    Move& move(unsigned number) // give the numberth move, existance (and legitmicy) should already be checked
    {
        return d_mlist[d_allowed[number]];
    }

    unsigned index() // currend index
    {
        return d_index;
    }
    void add(unsigned field); // add a field
    void copy(unsigned org);  // copy d_mlist[org] to the next
    void increment();         // increase the number of moves, to be called when finding a move is finished
    void capture() {
        d_mlist[d_index].setcapture();
    }
};
} // namespace klaas

#endif
