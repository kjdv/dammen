/* game/ai.cc
 *
 * Copyright (c) 2006-2009, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

// 9-7-2009 multithreader added

#include"game.ih"

#ifdef _OPENMP
#include <omp.h>
#endif

void Game::ai()
{
  if(d_factory.npossible() == 1) // if there is only one possible move, do it iimidiately
  {
    d_clicks = d_factory.move(0);
    move();
    return;
  }
	
  int max = d_whitemove ? 9999999 : -9999999; // black wants a high number, white a low one
  unsigned movenr = 0;

#ifdef _OPENMP
#pragma omp parallel for private(movenr) schedule(dynamic, 1)
#endif
  for(int i = 0; i < (int)d_factory.npossible(); ++i) // iterate over all possible moves
  {
    Setup *aibuffer = new Setup[s_aidepth2 + 1];
    aibuffer[0] = *this; // take this setup
    aibuffer[0].Setup::moveai(*this, i); // and make a move
    int temp = airec(aibuffer, 1); // and recurse
    
    if(!d_whitemove && temp > max) // maximize for black, minimize for white
    {
      max = temp;
      movenr = i;
    }
    else if(d_whitemove && temp < max)
    {
      max = temp;
      movenr = i;
    }

    delete [] aibuffer;
  }
  d_clicks = d_factory.move(movenr); // select the move
	
  move(); // and do it
}
