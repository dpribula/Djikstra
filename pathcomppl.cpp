/**
* @file pathcomppl.cpp
* @author David Pribula
*/
#include "pathcomppl.h"


PathCompPL::PathCompPL()
{
}
bool PathCompPL::betterThan(const PathInfo& path1, const PathInfo& path2){
	
	
	if (path1.getTotalPrice() == path2.getTotalPrice())
		return path1.getTotalLength() < path2.getTotalLength();
	else
		return path1.getTotalPrice() < path2.getTotalPrice();
	
}

PathCompPL::~PathCompPL()
{
}
