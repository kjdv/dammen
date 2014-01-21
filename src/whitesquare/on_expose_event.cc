/* whitesquare/on_expose_event.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"whitesquare.ih"

bool Whitesquare::on_expose_event(GdkEventExpose *event)
{
	s_whitesquare->render_to_drawable(d_window, get_style()->get_black_gc(), 0, 0, 0, 0, 50, 50, Gdk::RGB_DITHER_NONE, 0, 0);
	return true;
}
