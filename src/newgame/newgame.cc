/* newgame/newgame.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"newgame.ih"
#include<gtkmm/stock.h>

Newgame::Newgame() : d_rbuttons(false, 10), d_okbuttons(false, 10), d_d1("Easy"), d_d2("Normal"), d_d3("Hard"), d_ok(Stock::OK), d_cancel(Stock::CANCEL)
{
	set_title("Select difficulty:");
	set_border_width(10);

	RadioButton::Group group = d_d1.get_group();
	d_d2.set_group(group);
	d_d3.set_group(group);

	get_vbox()->pack_start(d_rbuttons);
	get_vbox()->pack_start(d_sep);
	get_vbox()->pack_start(d_okbuttons);
	
	d_rbuttons.pack_start(d_d1);
	d_rbuttons.pack_start(d_d2);
	d_rbuttons.pack_start(d_d3);

	d_okbuttons.add(d_actions);
	d_actions.pack_start(d_cancel);
	d_actions.pack_start(d_ok);

	d_rbuttons.set_border_width(10);
	d_okbuttons.set_border_width(10);

	d_cancel.signal_clicked().connect(sigc::mem_fun(*this, &Newgame::do_cancel));
	d_ok.signal_clicked().connect(sigc::mem_fun(*this, &Newgame::do_ok));
	
	d_d2.set_active();
	show_all_children();
}
																		
