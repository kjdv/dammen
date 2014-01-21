/* board/board.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/*
 * implementation of the Bord-constructor
 *
 */

#include"board.ih"
#include<gtkmm/stock.h>

Board::Board() : d_bord(false, 10), d_msg(false, 10), d_label("White's turn.", true), d_table(10, 10) // 10x10 Blacksquare
							 ,d_new(Stock::NEW), d_open(Stock::OPEN), d_save(Stock::SAVE), d_quit(Stock::QUIT)
{
	set_title("Dammen");
	set_border_width(0); // set the margin
	set_default_size(500, 500);

	d_blacksquares = new Blacksquare[50];
	d_whitesquares = new Whitesquare[50];
	
	Blacksquare::setptr(d_blacksquares); // make sure all squares know of each other, so their view get's updared simultaniously
	Blacksquare::setlabel(&d_label);
	Blacksquare::setgame(&d_game);

	unsigned vc = 0;
	unsigned wc = 0;
	for(int i = 0; i < 10; ++i) // place all fields on the board
		for(int j = 0; j < 10; ++j)
			{
				if((i % 2 && !(j % 2)) || (!(i % 2) && j % 2))
					{
						d_table.attach(d_blacksquares[vc], j, j + 1, i, i + 1);
						d_blacksquares[vc].setnummer(vc + 1);
						++vc;
					}
				else
					{
						d_table.attach(d_whitesquares[wc], j, j + 1, i, i + 1);
						++wc;
					}
			}

	add(d_top);
	d_top.pack_start(d_menu);
	d_top.pack_start(d_bord);
	d_top.pack_start(d_msg);

	d_menu.set_border_width(10);
	d_bord.set_border_width(10);
	d_msg.set_border_width(10);

	d_menu.pack_start(d_buttons);
	d_bord.pack_start(d_table);
	d_msg.pack_start(d_label);

	d_buttons.pack_start(d_new);
	d_buttons.pack_start(d_open);
	d_buttons.pack_start(d_save);
	d_buttons.pack_start(d_quit);

	d_new.signal_clicked().connect(sigc::mem_fun(*this, &Board::do_new));
	d_open.signal_clicked().connect(sigc::mem_fun(*this, &Board::do_open));
	d_save.signal_clicked().connect(sigc::mem_fun(*this, &Board::do_save));
	d_quit.signal_clicked().connect(sigc::mem_fun(*this, &Board::do_quit));
						
	show_all_children(); // show everything
}
