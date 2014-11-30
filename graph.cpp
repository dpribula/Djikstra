/**
* @file graph.cpp
* @author David Pribula
*/
#include "graph.h"



Graph::Graph()
{
}
int Graph::addVertex(const string& vertex){
	
	if (m_vertices.find(vertex) != m_vertices.end())
		return 1;
	m_vertices.insert(vertex);
	return 0;
}
int Graph::checkAddingEdge(const string& from, const string& to){
	bool checkFrom = 0;
	bool checkTo = 0;
	//if (from.compare(to) == 0) // not in task
	//	return 2;

	if (m_vertices.find(from) == m_vertices.end())
		checkFrom = 1;
	if (m_vertices.find(to)==m_vertices.end())
		checkTo = 1;
	if (checkFrom == 1 || checkTo == 1)
		return 2;
	for (list<pair<pair<string, string>, EdgeInfo> >::iterator it = m_edges[from].begin(); it != m_edges[from].end(); it++){
		if (it->first.second.compare(to) ==0)
			return 1;
	}
	return 0;
}
int Graph::addEdge(const string& from, const string& to, int length, int price){
	int x = checkAddingEdge(from, to);
	if (x == 0){
		pair<pair<string, string>, EdgeInfo> edg;
		EdgeInfo ei(length, price);
		edg.first.first = from;
		edg.first.second = to;
		edg.second = ei;

		m_edges[from].push_back(edg);
	}

	return x;
}
int Graph::addBidirectionalEdge(const string& vertex1, const string& vertex2, int length, int price){
	int x = checkAddingEdge(vertex1, vertex2);
	int y = checkAddingEdge(vertex2, vertex1);
	if (x == 0 && y == 0){
		pair<pair<string, string>, EdgeInfo> edge;
		EdgeInfo ei(length, price);
		edge.first.first = vertex1;
		edge.first.second = vertex2;
		edge.second = ei;
		m_edges[vertex1].push_back(edge);
		edge.first.first = vertex2;
		edge.first.second = vertex1;
		m_edges[vertex2].push_back(edge);
		return 0;
	}
	if (x == 2 || y == 2)
		return 2;

	return 1;
}
int Graph::setEdgePrice(const string& from, const string& to, int price){
	
	for (list<pair<pair<string, string>, EdgeInfo> >::iterator it = m_edges[from].begin(); it != m_edges[from].end(); it++){
		if (it->first.first.compare(from) == 0 && it->first.second.compare(to) == 0){
			it->second.setPrice(price);
			return 0;
		}
	}
	return 1;
	
}
/**
*@brief add edge to graph
*@param allVert vertex from
*@param from  vertex to
*@return 0 if added 1 if vertex is already in graph
*/
map<string, info> setBasicGraph(set<string> allVert,string from){
	map<string, info> djikstra;
	pair<string, info> temp;
	PathInfo noPath;
	noPath.addEdge(EdgeInfo(0, 0));

	temp.second.first = noPath;

	temp.second.second = "";
	for (std::set<string>::iterator it = allVert.begin(); it != allVert.end(); it++){

		if (it->compare(from) == 0){

			temp.second.first = PathInfo();
			temp.first = *it;
			djikstra.insert(temp);
			temp.second.first = noPath;


		}


		temp.first = *it;
		djikstra.insert(temp);
	}
	return djikstra;
}
list<string> Graph::shortestPath(const string& from, const string& to, PathComp* pc) const{
	if (m_vertices.find(from) == m_vertices.end() || m_vertices.find(from) == m_vertices.end())
		return list<string>();
	std::priority_queue<pair<PathInfo, string>, vector<pair<PathInfo, string> >, QueueComp> myQueue(pc);
	myQueue.push(pair<PathInfo, string>(PathInfo(),from));
	list<string> result;
	if (from == to){
		result.push_back(from);
		return result;
	}
	//long long intMaxcheck = INT_MAX;
	set<string> done;
	map<string, info> djikstra;
	PathInfo noPath;
	noPath.addEdge(EdgeInfo(0, 0));
	djikstra = setBasicGraph(m_vertices, from);
	
	string currentVertex = from;
	PathInfo tempPath;

	list<pair<pair<string, string>, EdgeInfo> > edges;
	while (!myQueue.empty()){
		done.insert(currentVertex);
		if (currentVertex == to)
			break;
		if(m_edges.find(currentVertex)!=m_edges.end())
		{	
			edges = m_edges.at(currentVertex);
			for (list<pair<pair<string, string>, EdgeInfo> > ::iterator it = edges.begin();
				it != edges.end(); it++){
				
				if (currentVertex.compare(it->first.first) == 0){
					
					tempPath = djikstra[it->first.second].first;
					if ((tempPath.getTotalLength() == 0 && tempPath.getTotalPrice() == 0)){
						tempPath = djikstra[it->first.first].first;
						tempPath.addEdge(it->second);
						djikstra[it->first.second].first = tempPath;
						djikstra[it->first.second].second = currentVertex;
					}
					else{
						tempPath = djikstra[it->first.first].first;
						tempPath.addEdge(it->second);
						if (pc->betterThan(tempPath, djikstra[it->first.second].first)){
							djikstra[it->first.second].first = tempPath;
							djikstra[it->first.second].second = currentVertex;
						}
					}



					if (done.find(it->first.second) == done.end()){
						myQueue.push(pair<PathInfo, string>(djikstra[it->first.second].first, it->first.second));
					}

				}
			}
				

		}
		bool rightVertex = false;
		while (!rightVertex&&!myQueue.empty()){
			myQueue.pop();
			if (!myQueue.empty())
				currentVertex = myQueue.top().second;
			if (done.find(currentVertex) == done.end()){
				rightVertex = true;
			}
		}
			
	}
	currentVertex = to;
	result.push_front(currentVertex);
	do{
		
		if (currentVertex == "")
			return list<string>();
		currentVertex = djikstra[currentVertex].second;
		result.push_front(currentVertex);

	} while (currentVertex != from);
	
	return result;

}

Graph::~Graph()
{
}
