/**
* @file queuecomp.h
* @author David Pribula
*/
#ifndef QUEUECOMP_H
#define QUEUECOMP_H

#include <string>
#include "pathcomp.h"
#include "pathinfo.h"
using namespace std;
/**
*@brief constructor
*/
class QueueComp
{
public:
	//QueueComp();
	/**
	*@brief constructor
	*@param pc
	*/
	QueueComp(PathComp* pc);
	/**
	*@brief constructor
	*@param item1 j
	*@param item2 j
	*@return hh
	*/
	bool operator () (const pair<PathInfo, string>& item1, const pair<PathInfo, string>& item2);
	/**
	*@brief constructor
	*/
	~QueueComp();
private:
	/**
	*@brief constructor
	*/
	PathComp* m_pathComp;
};
#endif

