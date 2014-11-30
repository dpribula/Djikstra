/**
* @file pathinfo.h
* @author David Pribula
*/#ifndef PATHINFO_H
#define PATHINFO_H

#include "edgeinfo.h"
/**
*@brief constructor
*/
class PathInfo
{
public:
	/**
	*@brief constructor
	*/
	PathInfo();
	/**
	*@brief constructor
	*@param edge hl
	*@return void
	*/
	void addEdge(const EdgeInfo& edge);
	/**
	*@brief constructor
	*@return l
	*/
	int getTotalLength() const;
	/**
	*@brief constructor
	*@return l
	*/
	int getTotalPrice() const;

	/**
	*@brief constructor
	*/
	virtual ~PathInfo();
private:
	/**
	*@brief constructor
	*/
	int m_pathLength;
	/**
	*@brief constructor
	*/
	int m_pathPrice;
	
	
};
#endif
