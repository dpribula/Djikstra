/**
* @file queuecomp.cpp
* @author David Pribula
*/
#include "queuecomp.h"


//QueueComp::QueueComp()
//{
//}
QueueComp::QueueComp(PathComp* pc):m_pathComp(pc){}
bool QueueComp::operator()(const pair<PathInfo, string>& item1, const pair<PathInfo, string>& item2){
	if (item1.first.getTotalLength() == item2.first.getTotalLength() && item1.first.getTotalPrice() == item2.first.getTotalPrice())
		return item1.second.compare(item2.second) > 0;
	return m_pathComp->betterThan(item2.first, item1.first);
	
}

QueueComp::~QueueComp()
{
}
