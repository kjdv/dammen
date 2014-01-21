/* whitesquare/whitesquare.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"whitesquare.ih"

// defined in images/ directory
extern guint8 whitesquare[];

RefPtr<Pixbuf> Whitesquare::s_whitesquare;

Whitesquare::Whitesquare() : ObjectBase("whitesquare")
{
	set_flags(NO_WINDOW);

	if(!s_whitesquare)
		s_whitesquare = Pixbuf::create_from_inline(-1, whitesquare);
}
