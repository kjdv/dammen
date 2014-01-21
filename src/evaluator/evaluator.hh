/* evaluator/evaluator.hh
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/*
 * This is a set of rules which detirmine which setup's of the board are good and which are not
 * The evaluate()-function calls the other functions and returns a value. A higher value means good for black
 *
 */

#ifndef _EVALUATOR_HH_
#define _EVALUATOR_HH_
#include"../field/field.hh"

// defines for the rules
#define UNBALANCED_PENALTY 5 // 10
#define CORNER 5 // 10
#define MIDDLE_1 10 // 20
#define MIDDLE_2 5 // 10
#define SUBMIDDLE_1 3 // 5
#define SUBMIDDLE_2 5 // 10
#define BOUNDARY_1 20 // 20
#define BOUNDARY_2 15 // 15
#define CENTRAL 20 // 20
#define COMPACT 20 // 20
#define PIECEVALUE 250
#define QUEENVALUE 1000
#define RANDOM_ELEMENT 5
#define LOCKVALUE 50 // 50
#define ORPHAN 50 // 50
#define TBP_ROW3 25 // 50
#define TBP_ROW2 100 // 150
#define TBP_ROW1 500 // 500
#define TOOFAR 50 // 50
#define TRAPVALUE 80 // 80
#define BLOCKVALUE_1 180 // 180
#define BLOCKVALUE_2 360 // 360

namespace klaas
{
	int evaluate(Field *setup); // Function that calls the other functions.

	int countpieces(Field *setup); // simply count the number of pieces on the board
	int compact(Field *setup); // is the setup compact (are the pieces close to each other?)
	int central(Field *setup); // are the pieces in the middle of the board?
	int orphan(Field *setup); // are there pieces all alone (vulnerable)
	int tobepromoted(Field *setup); // is a piece about to promote to queen?
	int boundary(Field *setup); // are the pieces on the border tacticly placed
	int behind(Field *setup); // are the pieces in the back tacticly placed
	int balanced(Field *setup); // is one of the players significantly stronger on one side?
	int lock(Field *setup); // try to avoid 'locks'
	int toofar(Field *setup); // it's in general dangerous to advance to far too quick

	int endgame(Field *setup); // main rule for the endgame, calls the other rules (including the above declarated countpieces(), tobepromotet() and lock()
	int queentrap(Field *setup); // let the queens build a 'trap'
	int block(Field *setup); // make sure enemy pieces are blocked

	void printstatus(Field *setup); // for program evaluation/debugging purposes
	

	bool enemy(Field &other, state self); // helper function
	bool ally(Field &other, state self); // analogous to enemy()
}

#endif
