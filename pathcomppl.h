/**
* @file pathcomppl.h
* @author David Pribula
*/
#ifndef PATHCOMPPL_H
#define PATHCOMPPL_H

#include "pathcomp.h"
/**
*@brief constructor
*/
class PathCompPL:public PathComp
{
public:
	/**
	*@brief constructor
	*/
	PathCompPL();
	/**
	*@brief constructor
	*@param path1 jl
	*@param path2 jk
	*@return bool jk
	*/
	virtual bool betterThan(const PathInfo& path1, const PathInfo& path2);
	/**
	*@brief constructor
	*/
	virtual ~PathCompPL();
};
#endif

