
//typedef map< string, EdgeInfo > edges;
///**
//* @brief edgesFromVertex represents vertices and edges in graph
//*/
//typedef map< string, edges > edgesFromVertex;
//
//
//
//typedef std::priority_queue< pair<PathInfo, string>, std::vector< pair<PathInfo, string> >, QueueComp> myQueue; //Q
//typedef map< string, pair<PathInfo, string> > shortestPaths;  //S
//
//
//list<string> Graph::shortestPath(const string& from, const string& to, PathComp* pc) const  {
//
//	//Test : if graph contains vertices from, to
//	if (!containVertex(from) || !containVertex(to))  {
//		return list<string>();
//	}
//
//
//	myQueue queue(pc);   //priority queue
//	shortestPaths sp;
//
//
//
//
//
//	sp[from] = make_pair(PathInfo(), from);
//
//	queue.push(sp[from]);
//
//
//	while (!queue.empty())   {
//		pair<PathInfo, string> min = queue.top();
//		queue.pop();
//
//
//		if (min.second.compare(to) == 0) {
//			break;
//		}
//
//		for (edges::const_iterator it = graph_efv.find(min.second)->second.begin(); it != graph_efv.find(min.second)->second.end(); it++)  {
//			PathInfo minPath = min.first;
//			minPath.addEdge(it->second);
//
//			if ((sp.find(it->first) == sp.end()) || (pc->betterThan(minPath, sp[it->first].first)))  {
//				sp[it->first].first = minPath;
//				sp[it->first].second = min.second;
//				queue.push(make_pair(minPath, it->first));
//			}
//		}
//	}
//
//	if (sp.find(to) == sp.end())   {
//		return list<string>();
//	}
//
//	std::list<std::string> predecessors;
//
//	std::string pred = to;
//
//	while (pred != from) {
//		predecessors.push_front(pred);
//		pred = sp[pred].second;
//	}
//
//	predecessors.push_front(from);
//
//	return predecessors;
//}