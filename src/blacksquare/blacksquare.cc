/* blacksquare/blacksquare.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include "blacksquare.ih"

// defined in the images/ directory
extern guint8 empty[];
extern guint8 white[];
extern guint8 black[];
extern guint8 whitequeen[];
extern guint8 blackqueen[];

// static members
Game *Blacksquare::s_game;
RefPtr<Pixbuf> Blacksquare::s_empty;
RefPtr<Pixbuf> Blacksquare::s_white;
RefPtr<Pixbuf> Blacksquare::s_black;
RefPtr<Pixbuf> Blacksquare::s_whitequeen;
RefPtr<Pixbuf> Blacksquare::s_blackqueen;

Blacksquare *Blacksquare::s_allsquares = 0;
Label *Blacksquare::s_label;

Blacksquare::Blacksquare() : ObjectBase("blacksquare")
{
	set_flags(NO_WINDOW);

	this->signal_clicked().connect(sigc::mem_fun(*this, &Blacksquare::do_clicked));

	if (!s_empty) // load png-files
	{
		s_empty = Pixbuf::create_from_inline(-1, ::empty);
		s_white = Pixbuf::create_from_inline(-1, white);
		s_black = Pixbuf::create_from_inline(-1, black);
		s_whitequeen = Pixbuf::create_from_inline(-1, whitequeen);
		s_blackqueen = Pixbuf::create_from_inline(-1, blackqueen);
	}
}
