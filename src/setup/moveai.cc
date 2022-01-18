/* setup/moveai.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "setup.ih"

void Setup::moveai(Setup& other, unsigned index) {
    unsigned n      = other.d_factory.move(index).priority() - 1;
    unsigned source = 0; // no real need to initialize these to zero, purely estatical (I want to compile it white -Wall
    unsigned target = 0; // whitout getting warnings)

    for(unsigned i = 0; i < n; ++i) {
        source = other.d_factory.move(index).field(i);     // from
        target = other.d_factory.move(index).field(i + 1); // to

        this->d_setup[target].setstate(d_setup[source].getstate());
        this->d_setup[source].setstate(EMPTY);

        // remove pieces
        if(target + 6 < source || source + 6 < target)
            this->d_setup[source].erase(d_setup, target);
    }

    if(d_whitemove && target < 5) // promote?
        this->d_setup[target].setstate(WHITEQUEEN);
    else if(!d_whitemove && target > 44)
        this->d_setup[target].setstate(BLACKQUEEN);

    this->d_whitemove = this->d_whitemove ? false : true;
}
