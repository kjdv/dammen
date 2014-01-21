/* game/init.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"game.ih"

void Game::init(diff d)
{
	Setup::init();

	d_log = "";
	d_counter = 1;

	switch(d)
		{
		case EASY:
			s_aidepth1 = 2;
			s_aidepth2 = 5;
			break;
		case NORMAL:
			s_aidepth1 = 4;
			s_aidepth2 = 9;
			break;
		case HARD:
			s_aidepth1 = 6;
			s_aidepth2 = 17;
			break;
		}

	d_msg = d_whitemove ? "White's turn." : "Black's turn.";
}
