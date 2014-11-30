/**
* @file edgeinfo.cpp
* @author David Pribula
*/
#include "edgeinfo.h"


EdgeInfo::EdgeInfo()
{
}
EdgeInfo::EdgeInfo(int l, int p):m_length(l), m_prize(p){}

int EdgeInfo::getLength()const{
	return m_length;
}
int EdgeInfo::getPrice()const{
	return m_prize;
}
void EdgeInfo::setPrice(int p){
	m_prize = p;
}
void EdgeInfo::setLength(int l){
	m_length = l;
}


EdgeInfo::~EdgeInfo()
{
}
