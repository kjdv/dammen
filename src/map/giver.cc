/* map/giver.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "map.ih"

unsigned klaas::giver(unsigned source, unsigned target) {
    unsigned sy = source / 5;
    unsigned ty = target / 5;
    unsigned sx = (source - sy * 5) * 2 + ((sy % 2) ? 0 : 1);
    unsigned tx = (target - ty * 5) * 2 + ((ty % 2) ? 0 : 1);

    if(source > target) {
        if(tx < sx)
            return 1;
        else
            return 2;
    } else {
        if(tx < sx)
            return 3;
        else
            return 4;
    }
    return 0;
}
