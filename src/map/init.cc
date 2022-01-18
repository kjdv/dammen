/* map/init.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "map.ih"

void Map::init(unsigned number) {
    unsigned y = number / 5;
    unsigned x = (number - y * 5) * 2 + ((y % 2) ? 0 : 1);

    unsigned reach1 = y < x ? y : x;
    unsigned reach2 = y < (9 - x) ? y : (9 - x);
    unsigned reach3 = (9 - y) < x ? (9 - y) : x;
    unsigned reach4 = (9 - y) < (9 - x) ? (9 - y) : (9 - x);

    d_r1    = new unsigned[reach1 + 1];
    d_r1[0] = reach1;
    for(unsigned i = 1; i < reach1 + 1; ++i)
        d_r1[i] = fieldreach1(number, i);

    d_r2    = new unsigned[reach2 + 1];
    d_r2[0] = reach2;
    for(unsigned i = 1; i < reach2 + 1; ++i)
        d_r2[i] = fieldreach2(number, i);

    d_r3    = new unsigned[reach3 + 1];
    d_r3[0] = reach3;
    for(unsigned i = 1; i < reach3 + 1; ++i)
        d_r3[i] = fieldreach3(number, i);

    d_r4    = new unsigned[reach4 + 1];
    d_r4[0] = reach4;
    for(unsigned i = 1; i < reach4 + 1; ++i)
        d_r4[i] = fieldreach4(number, i);
}
