/* game/klik.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"game.ih"

void Game::click(unsigned field)
{
	d_clicks.add(field - 1);
	
	if(d_capture)
		d_clicks.setcapture();
	d_msg = tostring(d_clicks);
		
	if(d_clicks.priority() == d_factory.move(0).priority())
		{
					if(!move())
						d_msg = "Illegal move!";
		}
	
	moveresolver();
}
