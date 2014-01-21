 /* evaluator/boundary.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/*
 * Are the pieces on the boundary in a strong position, for example:
 *
 * |. .           | .
 * | . .          |. .
 * |o.o.          | .
 * |.o.  = strong |.o. = weak
 * |o.            |o.
 * |. .           |. .
 *
 */

#include"evaluator.ih"

int klaas::boundary(Field *setup)
{
	int ret = 0;

	unsigned i = 5;
	while(i < 45)
		{
			// i % 10 == 5
			if(setup[i].getstate() == BLACK)
				{
					if(i > 24)
						ret += BOUNDARY_1;

					if(setup[i + 5].getstate() == WHITE)
						ret += BOUNDARY_1;
					else if(setup[i + 5].getstate() == BLACK && setup[i + 10].getstate() == BLACK)
						{
							ret += BOUNDARY_1;
							if(setup[i + 11].getstate() == BLACK)
								ret += BOUNDARY_2;
						}
					/*					else if(setup[i + 5].getstate() == BLACK)
											ret -= BOUNDARY_1;*/
				}
			else if(setup[i].getstate() == WHITE)
				{
					if(i < 24)
						ret -= BOUNDARY_1;

					if(setup[i - 5].getstate() == BLACK)
						ret -= BOUNDARY_1;
					else if(setup[i - 5].getstate() == WHITE && (i > 5 && setup[i - 10].getstate() == WHITE))
						{
							ret -= BOUNDARY_1;
							if(setup[i - 9].getstate() == WHITE)
								ret -= BOUNDARY_2;
						}
					/*					else if(setup[i - 5].getstate() == WHITE)
											ret += BOUNDARY_1;*/
				}
			i += 9;
			
			// i % 10 == 4
			if(setup[i].getstate() == BLACK)
				{
					if(i > 25)
						ret += BOUNDARY_1;

					if(setup[i + 5].getstate() == WHITE)
						ret += BOUNDARY_1;
					else if(setup[i + 5].getstate() == BLACK && (i < 44 && setup[i + 10].getstate() == BLACK))
						{
									ret += BOUNDARY_1;
									if(setup[i + 9].getstate() == BLACK)
										ret += BOUNDARY_2;
						}
					/*					else if(setup[i + 5].getstate() == BLACK)
											ret -= BOUNDARY_1;*/
				}
			else if(setup[i].getstate() == WHITE)
				{
					if(i < 25)
						ret -= BOUNDARY_1;
					
					if(setup[i - 5].getstate() == BLACK)
						ret -= BOUNDARY_1;
					else if(setup[i - 5].getstate() == WHITE && setup[i - 10].getstate() == WHITE)
						{
							ret -= BOUNDARY_1;
							if(setup[i - 11].getstate() == WHITE)
								ret -= BOUNDARY_2;
						}
					/*					else if(setup[i - 5].getstate() == WHITE)
											ret += BOUNDARY_1;*/
				}
			++i;
		}
	
	return ret;
}
