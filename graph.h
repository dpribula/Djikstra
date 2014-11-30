/**
* @file graph.h
* @author David Pribula
*/
#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include<list>
#include <queue>
#include<map>
#include <climits>
#include<set>
#include "pathcomp.h"
#include"queuecomp.h"


using namespace std;
/**
*@brief edges 
*/
typedef pair<pair<string, string>, EdgeInfo> Edge;
/**
*@brief vertices with path for queue
*/
typedef pair<PathInfo, string> info;
/**
*@brief represent graph
*/
class Graph
{
public:
	/**
	*@brief constructor
	*/
	Graph();
	/**
	*@brief add vertex to graph
	*@param vertex simple vertex
	*@return 0 if added 1 if vertex is already in graph
	*/
	int addVertex(const string& vertex);
	/**
	*@brief add edge to graph
	*@param from vertex from
	*@param to  vertex to
	*@param length l
	*@param price l
	*@return 0 if added 1 if vertex is already in graph
	*/
	int addEdge(const string& from, const string& to, int length, int price);
	/**
	*@brief add bidvertex to graph 
	*@param vertex1 simple vertex
	*@param vertex2 lkj
	*@param length l
	*@param price l
	*@return 0 if added 1 if vertex is already in graph
	*/
	int addBidirectionalEdge(const string& vertex1, const string& vertex2, int length, int price);
	/**
	*@brief add edge to graph
	*@param from vertex from
	*@param to price l
	*@param price j
	*@return 0 if added 1 if vertex is already in graph
	*/
	int setEdgePrice(const string& from, const string& to, int price);
	/**
	*@brief add edge to graph
	*@param from vertex from
	*@param to vertex to
	*@return 0 if added 1 if vertex is already in graph
	*/
	int checkAddingEdge(const string& from, const string& to);
	/**
	*@brief add edge to graph
	*@param from vertex from
	*@param to  vertex to
	*@param pc hk
	*@return 0 if added 1 if vertex is already in graph
	*/
	list<string> shortestPath(const string& from, const string& to, PathComp* pc) const;
	/**
	*@brief constructor
	*/
	virtual ~Graph();
private:
	/**
	*@brief constructor
	*/
	map<string,list<Edge> > m_edges;
	/**
	*@brief constructor
	*/
	set<string> m_vertices;

};
#endif

