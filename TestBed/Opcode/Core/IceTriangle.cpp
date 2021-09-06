///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains a handy triangle class.
 *	\file		IceTriangle.cpp
 *	\author		Pierre Terdiman
 *	\date		January, 17, 2000
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Precompiled Header
#include "Stdafx.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains a triangle class.
 *
 *	\class		Tri
 *	\author		Pierre Terdiman
 *	\version	1.0
 *	\date		08.15.98
 *	\warning	THIS IS ONLY A VERY LITTLE SUBSET OF THE ORIGINAL ICE CLASS
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Computes the triangle center.
 *	\param		verts			[in] the list of indexed vertices
 *	\param		center			[out] the computed center
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Triangle::Center(const Point* verts, Point& center)	const
{
	if(verts)
	{
		const Point& p0 = verts[mVRef[0]];
		const Point& p1 = verts[mVRef[1]];
		const Point& p2 = verts[mVRef[2]];
		center = (p0+p1+p2)*INV3;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Checks whether the triangle is degenerated or not. A degenerated triangle has two common vertex references. This is a zero-area triangle.
 *	\return		true if the triangle is degenerated
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Triangle::IsDegenerate()	const
{
	if(mVRef[0]==mVRef[1])	return true;
	if(mVRef[1]==mVRef[2])	return true;
	if(mVRef[2]==mVRef[0])	return true;
	return false;
}