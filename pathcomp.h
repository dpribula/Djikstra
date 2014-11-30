/**
* @file pathcomp.h
* @author David Pribula
*/
#ifndef PATHCOMP_H
#define PATHCOMP_H
#include "pathinfo.h"
/**
*@brief constructor
*/
class PathComp{
public:
	/**
	*@brief constructor
	*@param path1 jl
	*@param path2 jk
	*@return bool jk
	*/
	virtual bool betterThan(const PathInfo& path1, const PathInfo& path2) = 0;
};
#endif