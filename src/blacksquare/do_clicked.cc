/* blacksquare/doe.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"blacksquare.ih"
#include<gtkmm/main.h>

void Blacksquare::do_clicked()
{
	s_game->click(d_number);

	s_label->set_text(s_game->msg());

	// redraw everything
	for(unsigned i = 0; i < 50; ++i)
		s_allsquares[i].queue_draw();
	s_label->queue_draw();
	
	while(Main::events_pending())
		Main::iteration();
				
	s_game->blackmove();
	s_label->set_text(s_game->msg());

	// again, redraw!
	for(unsigned i = 0; i < 50; ++i)
		s_allsquares[i].queue_draw();
	s_label->queue_draw();
	
	while(Main::events_pending())
		Main::iteration();
}
