/* blacksquare/blacksquare.hh
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* The gtk-interface for the black squares */

#ifndef _BLACKSQUARE_HH_
#define _BLACKSQUARE_HH_
#include<cstring>
#include<gtkmm/button.h>
#include<gdkmm/pixbuf.h>
#include<gtkmm/label.h>
#include"../game/game.hh"

namespace klaas
{	
	class Blacksquare: public Gtk::Button // it is actually a button
	{
		// the images
		static Glib::RefPtr<Gdk::Pixbuf> s_empty;
		static Glib::RefPtr<Gdk::Pixbuf> s_white;
		static Glib::RefPtr<Gdk::Pixbuf> s_black;
		static Glib::RefPtr<Gdk::Pixbuf> s_whitequeen;
		static Glib::RefPtr<Gdk::Pixbuf> s_blackqueen;

		unsigned d_number; // the number (1 <= d_number <= 50)
		static Game *s_game; // the game
		static Blacksquare *s_allsquares; // the other black squares
		static Gtk::Label *s_label;
		
	public:
		Blacksquare();

		void setnummer(unsigned number)
		{
			d_number = number;
		}

		static void setgame(Game *game)
		{
			s_game = game;
		}
		
		static void setptr(Blacksquare *blacksquares)
		{
			s_allsquares = blacksquares;
		}

		static void setlabel(Gtk::Label *label)
		{
			s_label = label;
		}

	protected:
		//gtk-stuff
		virtual void on_size_request(Gtk::Requisition *requisition);
		virtual void on_size_allocate(Gtk::Allocation &allocation);
		virtual void on_map()
		{
			Gtk::Widget::on_map();
		}
		virtual void on_unmap()
		{
			Gtk::Widget::on_unmap();
		}
		virtual void on_realize();
		virtual void on_unrealize();
		virtual bool on_expose_event(GdkEventExpose *event);

		Glib::RefPtr<Gdk::Window> d_window;
		Glib::RefPtr<Gdk::GC> d_gc;

		// if this square is clicked
		void do_clicked();
	};
}

#endif
