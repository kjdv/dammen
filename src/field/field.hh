/* field/field.hh
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* class for all black fields and their content */

#ifndef _FIELD_HH_
#define _FIELD_HH_
#include "../map/map.hh"
#include "../move/move.hh"

namespace klaas {
typedef enum { EMPTY,
               WHITE,
               BLACK,
               WHITEQUEEN,
               BLACKQUEEN } state; // The different states a field can have

class Field {
    state    d_state;  // the state
    unsigned d_number; // the number (0 <= d_number <= 49)
    bool     d_lock;   // is this piece to be removed (can't be removed again)

    Map d_map; // The indices of the reachable fields

    bool enemy(bool white) // is this field an enemy of white (or, if white == false, an enemy of black)?
    {
        if(d_lock)
            return false;
        if(white && (d_state == BLACK || d_state == BLACKQUEEN))
            return true;
        else if(!white && (d_state == WHITE || d_state == WHITEQUEEN))
            return true;
        return false;
    }

  public:
    Field()
      : d_state(EMPTY)
      , d_number(0)
      , d_lock(false)
      , d_map(0) {}
    Field(state st, unsigned number)
      : d_state(st)
      , d_number(number)
      , d_lock(false)
      , d_map(d_number) {}
    void operator=(Field const& other);

    state getstate() {
        return d_state;
    }
    void setstate(state st) {
        d_state = st;
    }

    // what can this piece do? save the results in list
    bool cancapture(Field* setup, Movelist& list, bool white = true, bool first = true);
    void canmove(Field* setup, Movelist& list);
    bool canqueencapture(Field* setup, Movelist& list, bool white = true, bool first = true);
    void canqueenmove(Field* setup, Movelist& list);

    // remove al pieces between here and target
    void erase(Field* setup, unsigned target);

    Map& map() {
        return d_map;
    }
};
} // namespace klaas

#endif
