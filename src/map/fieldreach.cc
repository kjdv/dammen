/* map/fieldreach.cc
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* These functions might be done more effieciently, but the should be done only once (when the program starts), therefore
 * improving them has no priority to me */

#include"map.ih"

unsigned klaas::fieldreach1(unsigned begin, unsigned offset)
{
	for(unsigned i = offset; i; --i)
		begin -= (begin / 5) % 2 ? 6 : 5;
	return begin;
}

unsigned klaas::fieldreach2(unsigned begin, unsigned offset)
{
	for(unsigned i = offset; i; --i)
		begin -= (begin / 5) % 2 ? 5 : 4;
	return begin;
}

unsigned klaas::fieldreach3(unsigned begin, unsigned offset)
{
	for(unsigned i = offset; i; --i)
		begin += (begin / 5) % 2 ? 4 : 5;
	return begin;
}

unsigned klaas::fieldreach4(unsigned begin, unsigned offset)
{
	for(unsigned i = offset; i; --i)
		begin += (begin / 5) % 2 ? 5 : 6;
	return begin;
}
