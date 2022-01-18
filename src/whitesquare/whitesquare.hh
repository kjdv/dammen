/* whitesquare/whitesquare.hh
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* gtk-interface for the white squares. they don't really do anything */

#ifndef _WHITESQUARE_HH_
#define _WHITESQUARE_HH_
#include <cstring>
#include <gtkmm/widget.h>

namespace klaas {
class Whitesquare : public Gtk::Widget {
    static Glib::RefPtr<Gdk::Pixbuf> s_whitesquare; // the image

  public:
    Whitesquare();

  protected:
    // gtk-stuff
    virtual void on_size_request(Gtk::Requisition* requisition);
    virtual void on_size_allocate(Gtk::Allocation& allocation);
    virtual void on_map() {
        Gtk::Widget::on_map();
    }
    virtual void on_unmap() {
        Gtk::Widget::on_unmap();
    }
    virtual void on_realize();
    virtual void on_unrealize();
    virtual bool on_expose_event(GdkEventExpose* event);

    Glib::RefPtr<Gdk::Window> d_window;
    Glib::RefPtr<Gdk::GC>     d_gc;
};
} // namespace klaas

#endif
