/***********************************************************************
OrthogonalCoordinateTransform - Coordinate transformation class for
orthogonal transformations (combinations of translations, rotations, and
uniform scalings).
Copyright (c) 2008-2012 Oliver Kreylos

This file is part of the Virtual Reality User Interface Library (Vrui).

The Virtual Reality User Interface Library is free software; you can
redistribute it and/or modify it under the terms of the GNU General
Public License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

The Virtual Reality User Interface Library is distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with the Virtual Reality User Interface Library; if not, write to the
Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
02111-1307 USA
***********************************************************************/

#ifndef VRUI_ORTHOGONALCOORDINATETRANSFORM_INCLUDED
#define VRUI_ORTHOGONALCOORDINATETRANSFORM_INCLUDED

#include <Geometry/OrthogonalTransformation.h>
#include <Vrui/CoordinateTransform.h>

namespace Vrui {

class OrthogonalCoordinateTransform:public CoordinateTransform
	{
	/* Elements: */
	private:
	OGTransform ogTransform; // The orthogonal transformation from user space to navigational space
	
	/* Constructors and destructors: */
	public:
	OrthogonalCoordinateTransform(const OGTransform& sOgTransform); // Wraps a coordinate transformation object around the given orthogonal transformation
	
	/* Methods from CoordinateTransform: */
	virtual Point transform(const Point& navigationPoint) const;
	virtual Point inverseTransform(const Point& userPoint) const;
	
	/* New methods: */
	const OGTransform& getTransform(void) const // Returns the current orthogonal transformation
		{
		return ogTransform;
		}
	void setTransform(const OGTransform& newOgTransform); // Sets the current orthogonal transformation
	};

}

#endif
