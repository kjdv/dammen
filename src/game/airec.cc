/* game/airec.cc
 *
 * Copyright (c) 2006-2009, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"game.ih"
#include"../evaluator/evaluator.hh"

int Game::airec(Setup *aibuffer, unsigned level)
{	
  aibuffer[level - 1].findmoves(); // find possible moves
			
  if(level >= s_aidepth1 && !(level % 2)) // optimize, only continue recursing if possible mistakes can't be corrected
  {
    if(!aibuffer[level - 1].d_capture && aibuffer[level - 1].d_factory.npossible() > 2)
      return evaluate(aibuffer[level - 1].d_setup);
  }

  if(aibuffer[level - 1].d_factory.npossible() == 0) // is the game won by any side?
    return aibuffer[level - 1].d_whitemove ? 99999999 : -99999999;
	
  int ret = aibuffer[level - 1].d_whitemove ? 99999999 : -99999999;
  int temp;
  for(unsigned i = 0; i < aibuffer[level - 1].d_factory.npossible(); ++i)
  {
    aibuffer[level] = aibuffer[level - 1]; // select the previous setup
    aibuffer[level].moveai(aibuffer[level - 1], i); // and do a move
			
    if(level == s_aidepth2) // maximum depth
      temp = evaluate(aibuffer[level].d_setup);
    else
      temp = airec(aibuffer, level + 1);
					
    if(aibuffer[level - 1].d_whitemove) // is the last move for black or for white?
    {
      if(temp < ret)
	ret = temp;
    }
    else
    {
      if(temp > ret)
	ret = temp;
    }
  }
	
  return ret;
}
