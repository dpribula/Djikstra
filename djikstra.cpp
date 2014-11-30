/**
* @file djikstra.cpp
* @author David Pribula
*/
#include "edgeinfo.h"
#include"graph.h"
#include "pathcomppl.h"

int main(){
	Graph g;
	list<string> test;
	
	
	PathCompPL comp;
	int x;
	g.addVertex("a");
	g.addVertex("b");
	g.addVertex("c");
	g.addVertex("d");
	g.addVertex("e");
	g.addVertex("f");

	
	
	
	g.addEdge("a", "c", 1, 1);
	g.addEdge("a", "b", 1, 1);
	g.addEdge("c", "d", 5, 5);
	g.addEdge("b", "d", 5, 5);
	g.addEdge("d", "e", 5, 5);
	
	
	
	
	
	
	test = g.shortestPath("a", "e", &comp);
	
	test = list<string>();

	
	return 0;
}