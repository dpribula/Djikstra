/**
* @file pathinfo.cpp
* @author David Pribula
*/
#include "pathinfo.h"


PathInfo::PathInfo():m_pathLength(0), m_pathPrice(0){}


int PathInfo::getTotalLength() const{
	return m_pathLength;
}
int PathInfo::getTotalPrice()const{
	return m_pathPrice;
}
void PathInfo::addEdge(const EdgeInfo& edge){
	m_pathLength += edge.getLength();
	m_pathPrice += edge.getPrice();
}



PathInfo::~PathInfo()
{
}
