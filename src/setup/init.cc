/* init/init.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "setup.ih"

void Setup::init() {
    d_whitemove = true;

    for(unsigned i = 0; i < 50; ++i) {
        if(i < 20)
            d_setup[i] = Field(BLACK, i);
        else if(i > 29)
            d_setup[i] = Field(WHITE, i);
        else
            d_setup[i] = Field(EMPTY, i);
    }
    findmoves();
}
