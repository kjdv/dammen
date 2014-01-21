/* move/operatorassign.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"move.ih"

void Move::operator=(Move const &other)
{
	this->d_size = other.d_size;
	this->d_capture = other.d_capture;

	if(this->d_list.size() == other.d_list.size()) // might be more efficient
		{
			for(unsigned i = 0; i < this->d_size; ++i)
				this->d_list[i] = other.d_list[i];
		}
	else
		this->d_list = other.d_list;
}
