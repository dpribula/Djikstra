/**
* @file edgeinfo.h
* @author David Pribula
*/
#ifndef EDGEINFO_H
#define EDGEINFO_H
#include <string>
using namespace std;/**
*@brief represent edge in graph
*/
class EdgeInfo
{
public:
	/**
	*@brief constructor
	*/
	EdgeInfo();
	/**
	*@brief constructor
	*@param l length of edge
	*@param p price of edge
	*/
	EdgeInfo(int l, int p);
	/**
	*@brief setter
	*@param p price of edge
	*/
	void setPrice(int p);
	/**
	*@brief setter
	*@param l length of edge
	*/
	void setLength(int l);
	/**
	*@brief getter
	*return length of edge
	*/
	int getLength() const;
	/**
	*@brief getter
	*return price of edge
	*/
	int getPrice() const;
	/**
	*@brief destructor
	*/
	virtual ~EdgeInfo();
private:
	/**
	*@brief length of edge
	*/
	int m_length;
	/**
	*@brief price of edge
	*/
	int m_prize;
	
};
#endif

