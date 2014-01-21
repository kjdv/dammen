/* newgame/newgame.hh
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* the pop-up dialog when you press 'New' */

#ifndef _NEWGAME_HH_
#define _NEWGAME_HH_
#include<gtkmm/dialog.h>
#include<gtkmm/radiobutton.h>
#include<gtkmm/box.h>
#include<gtkmm/separator.h>

namespace klaas
{
	class Newgame : public Gtk::Dialog
	{
	public:
		Newgame();
		
		unsigned d_diff;
		
	protected:
		Gtk::VBox d_top, d_rbuttons, d_okbuttons;
		Gtk::HBox d_actions;
		Gtk::RadioButton d_d1, d_d2, d_d3;
		Gtk::Button d_ok, d_cancel;
		Gtk::HSeparator d_sep;

		void do_ok();
		void do_cancel();
	};
}

#endif
