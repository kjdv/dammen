/* evaluator/printstatus.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include"evaluator.ih"
#include<iostream>

using namespace std;

extern bool s_endgame;

void klaas::printstatus(Field *setup)
{
	cout << "*** status ***\n" << endl;

	int count = 0;
	for(unsigned i = 0; i < 50; ++i)
		{
			if(setup[i].getstate() != EMPTY)
				++count;
		}
	if(count > 20)
		{
			cout << "countpieces:\t" << countpieces(setup) << endl;
			cout << "orphan:\t\t" <<  orphan(setup) << endl;
			cout << "tobepromoted:\t" << tobepromoted(setup) << endl;
			cout << "compact:\t" << compact(setup) << endl;
			cout << "central:\t" << central(setup) << endl;
			cout << "boundary:\t" << boundary(setup) << endl;
			cout << "behind:\t\t" << behind(setup) << endl;
			cout << "balanced:\t" << balanced(setup) << endl;
			cout << "lock:\t\t" << lock(setup) << endl;
		}
	else
		{
			cout << "countpieces:\t" << countpieces(setup) << endl;
			cout << "compact:\t" <<  compact(setup) << endl;
			cout << "tobepromoted:\t" << tobepromoted(setup) << endl;
			cout << "queentrap:\t" << queentrap(setup) << endl;
			cout << "block:\t\t" << block(setup) << endl;
		}

	cout << "\n" << endl;
}
