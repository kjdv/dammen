/* field/operatorassign.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"field.ih"

void Field::operator=(Field const &other)
{
	this->d_state = other.d_state;
	if(this->d_number != other.d_number)
	{
		this->d_number = other.d_number;
		this->d_map = other.d_map;
	}
}
