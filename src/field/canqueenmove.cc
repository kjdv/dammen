/* field/canqueenmove.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "field.ih"

void Field::canqueenmove(Field* setup, Movelist& list) {
    unsigned i = 1;

    // r1
    while(d_map.canr1(i) && setup[d_map.fieldr1(i)].d_state == EMPTY) {
        list.add(d_number);
        list.add(d_map.fieldr1(i));
        list.increment();
        ++i;
    }
    i = 1;

    // r2
    while(d_map.canr2(i) && setup[d_map.fieldr2(i)].d_state == EMPTY) {
        list.add(d_number);
        list.add(d_map.fieldr2(i));
        list.increment();
        ++i;
    }
    i = 1;

    // r3
    while(d_map.canr3(i) && setup[d_map.fieldr3(i)].d_state == EMPTY) {
        list.add(d_number);
        list.add(d_map.fieldr3(i));
        list.increment();
        ++i;
    }
    i = 1;

    // r4
    while(d_map.canr4(i) && setup[d_map.fieldr4(i)].d_state == EMPTY) {
        list.add(d_number);
        list.add(d_map.fieldr4(i));
        list.increment();
        ++i;
    }
}
