/* game/game.hh
 *
 * Copyright (c) 2006-2009, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General
 * Public Licence version 2, as publiced by the Free Software Foundation. See the file COPYRIGHT for details or write to
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* The game that is played, this class is still a bit of a mess */

#ifndef _GAME_HH_
#define _GAME_HH_
#include "../setup/setup.hh"
#include <string>

namespace klaas {
std::string tostring(Move& move); // make a string from this move

typedef enum { EASY,
               NORMAL,
               HARD } diff; // difficulty of ai

class Game : public Setup {
    Move     d_clicks;  // the move resulting from the squares the user (or the computer) clicks (ok, the name is a bit silly)
    unsigned d_counter; // the number of moves played

    static unsigned s_aidepth1; // how deep does the ai think?
    static unsigned s_aidepth2;

    bool move(); // do the current d_cliks move. Check if the move is legal
    void log();  // keep the log

    void ai();                                   // the ai
    int  airec(Setup* aibuffer, unsigned level); // recursieve function for ai()

    std::string d_msg; // the message in the user intergace
    std::string d_log; // the string containing the log

    void moveresolver(); // check if the given clicks already uniquely specify a move, and if so, do that move
  public:
    Game(diff d = NORMAL);

    void init(diff d);          // initialize the game
    void click(unsigned field); // the user clicks a square

    bool blackmove() {
        if(!d_whitemove) {
            ai();
            return true;
        }
        return false;
    }

    void aimove() // not used
    {
        ai();
    }

    std::string& msg() {
        return d_msg;
    }
    void readlog(std::string& filename);  // open a game
    void writelog(std::string& filename); // save the game
};
} // namespace klaas

#endif
