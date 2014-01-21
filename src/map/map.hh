/* map/map.hh
 *
 * Copyright (c) 2006, Klaas Jacob de Vries
 *
 * This file is part of dammen and may used, copied, modified and (re)destributed under the terms of the GNU General 
 * Public Licence version 2, as publiced by the Free Software foundation. See the file COPYRIGHT for details or write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

/* Map can save the field lying in the diagonals of al field, for quick access
 * r1 if top left, r2 top right, r3 down left, r4 down right */

#ifndef _MAP_HH_
#define _MAP_HH_

namespace klaas
{
	class Map
	{
		// the indices of the fields. element 0 is the number of reachable fields
		unsigned *d_r1;
		unsigned *d_r2;
		unsigned *d_r3;
		unsigned *d_r4;
	public:
		Map()
		{}
		Map(unsigned field)
		{
			init(field);
		}
		~Map();
		void operator=(Map const &other);

		void init(unsigned field);
		unsigned fieldr1(unsigned offset = 1)
		{
			return d_r1[offset];
		}
		unsigned fieldr2(unsigned offset = 1)
		{
			return d_r2[offset];
		}
		unsigned fieldr3(unsigned offset = 1)
		{
			return d_r3[offset];
		}
		unsigned fieldr4(unsigned offset = 1)
		{
			return d_r4[offset];
		}
		bool canr1(unsigned offset = 1)
		{
			return offset > d_r1[0] ? false : true;
		}
		bool canr2(unsigned offset = 1)
		{
			return offset > d_r2[0] ? false : true;
		}
		bool canr3(unsigned offset = 1)
		{
			return offset > d_r3[0] ? false : true;
		}
		bool canr4(unsigned offset = 1)
		{
			return offset > d_r4[0] ? false : true;
		}
	};

	// wich fields can be found, that is, how far to the border of the board
	unsigned fieldreach1(unsigned begin, unsigned offset = 1);
	unsigned fieldreach2(unsigned begin, unsigned offset = 1);
	unsigned fieldreach3(unsigned begin, unsigned offset = 1);
	unsigned fieldreach4(unsigned begin, unsigned offset = 1);

	unsigned giver(unsigned source, unsigned target); // what is the direction from source to target
}

#endif
