/* map/operatorassign.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "map.ih"

void Map::operator=(Map const& other) {
    if(this != &other) // prevent suicide
    {
        delete[] this->d_r1;
        delete[] this->d_r2;
        delete[] this->d_r3;
        delete[] this->d_r4;

        this->d_r1 = new unsigned[other.d_r1[0] + 1];
        for(unsigned i = 0; i < other.d_r1[0] + 1; ++i)
            this->d_r1[i] = other.d_r1[i];

        this->d_r2 = new unsigned[other.d_r2[0] + 1];
        for(unsigned i = 0; i < other.d_r2[0] + 1; ++i)
            this->d_r2[i] = other.d_r2[i];

        this->d_r3 = new unsigned[other.d_r3[0] + 1];
        for(unsigned i = 0; i < other.d_r3[0] + 1; ++i)
            this->d_r3[i] = other.d_r3[i];

        this->d_r4 = new unsigned[other.d_r4[0] + 1];
        for(unsigned i = 0; i < other.d_r4[0] + 1; ++i)
            this->d_r4[i] = other.d_r4[i];
    }
}
