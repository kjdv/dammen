/* blacksquare/on_realize.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* more or less copied from the gtkmm documentation */

#include"blacksquare.ih"

void Blacksquare::on_realize()
{
	Widget::on_realize();
	
	if(!d_window)
		{
			GdkWindowAttr attr;
			memset(&attr, 0, sizeof(attr));
			
			Allocation alloc = get_allocation();

			attr.x = alloc.get_x();
			attr.y = alloc.get_y();
			attr.width = alloc.get_width();
			attr.height = alloc.get_height();

			attr.event_mask = get_events() | EXPOSURE_MASK;
			attr.window_type = GDK_WINDOW_CHILD;
			attr.wclass = GDK_INPUT_OUTPUT;

			d_window = Gdk::Window::create(get_window(), &attr, GDK_WA_X | GDK_WA_Y);
			unset_flags(NO_WINDOW);
			set_window(d_window);

			d_window->set_user_data(gobj());
			d_gc = GC::create(d_window);
		}
}
