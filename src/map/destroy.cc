/* map/destroy.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "map.ih"

Map::~Map() {
    delete[] d_r1;
    delete[] d_r2;
    delete[] d_r3;
    delete[] d_r4;
}
