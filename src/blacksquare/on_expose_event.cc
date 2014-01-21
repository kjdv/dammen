/* blacksquare/on_expose_event.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"blacksquare.ih"

bool Blacksquare::on_expose_event(GdkEventExpose *event)
{
	//	for(unsigned i = 0; i < 50; ++i)
	//		s_allsquares[i].updateview();

	switch(s_game->getstate(d_number))
		{
		case WHITE:
			s_white->render_to_drawable(d_window, get_style()->get_black_gc(), 0, 0, 0, 0, 50, 50, Gdk::RGB_DITHER_NONE, 0, 0);
			break;
		case BLACK:
			s_black->render_to_drawable(d_window, get_style()->get_black_gc(), 0, 0, 0, 0, 50, 50, Gdk::RGB_DITHER_NONE, 0, 0);
			break;
		case WHITEQUEEN:
			s_whitequeen->render_to_drawable(d_window, get_style()->get_black_gc(), 0, 0, 0, 0, 50, 50, Gdk::RGB_DITHER_NONE, 0, 0);
			break;
		case BLACKQUEEN:
			s_blackqueen->render_to_drawable(d_window, get_style()->get_black_gc(), 0, 0, 0, 0, 50, 50, Gdk::RGB_DITHER_NONE, 0, 0);
			break;
		default:
			s_empty->render_to_drawable(d_window, get_style()->get_black_gc(), 0, 0, 0, 0, 50, 50, Gdk::RGB_DITHER_NONE, 0, 0);
		}
	return true;
}
