/* move/copy.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"move.ih"

void Movelist::copy(unsigned org)
{
	if(d_index + 1 >= d_mlist.size())
		{
			d_mlist.resize((d_index + 1) * 2);
			d_allowed.resize((d_index + 1) * 2);
		}

	d_mlist[++d_index] = d_mlist[org];
}
