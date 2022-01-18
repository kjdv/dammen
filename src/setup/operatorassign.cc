/* setup/operatorassign.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "setup.ih"

void Setup::operator=(Setup const& other) {
    for(unsigned i = 0; i < 50; ++i)
        this->d_setup[i] = other.d_setup[i];

    this->d_whitemove = other.d_whitemove;
}
