/* whitesquare/on_size_allocate.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"whitesquare.ih"

void Whitesquare::on_size_allocate(Allocation &allocation)
{
	set_allocation(allocation);
	if(d_window)
		d_window->move_resize(allocation.get_x(), allocation.get_y(), allocation.get_width(), allocation.get_height());
}
