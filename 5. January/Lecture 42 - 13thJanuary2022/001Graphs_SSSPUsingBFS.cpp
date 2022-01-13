/*

Computing SSSP using the BFS algorithm in an unweighted graph.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;

template <typename T>
class graph {
	map<T, list<T>> neighbourMap;
	bool isDirected;

	public :

		graph(bool isDirected=false) {
			this->isDirected = isDirected;
		}

		void addEdge(T u, T v) {
			neighbourMap[u].push_back(v);
			if(!isDirected) {
				neighbourMap[v].push_back(u);
			}
		}

		void print() {
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<T> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(T neighbour : neighbourList) {
					cout << neighbour << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

		void bfs(T s, T d) {

			cout << "bfs(" << s << ") : "; 
			unordered_set<T> visited;
			queue<T> q; // to track visited but unexplored vertices

			visited.insert(s);
			q.push(s);

			map<T, int> distanceMap;
			distanceMap[s] = 0;

			map<T, T> parentMap;
			parentMap[s] = s;

			while(!q.empty()) {
				T front = q.front();
				q.pop();

				cout << front << " ";
				list<T> neighbourList = neighbourMap[front];
				for(T neighbour : neighbourList) {
					if(visited.find(neighbour) == visited.end()) {
						visited.insert(neighbour);
						q.push(neighbour);
						distanceMap[neighbour] = 1 + distanceMap[front];
						parentMap[neighbour] = front;
					}
				}
			}

			cout << endl;

			for(pair<T, int> vertex : distanceMap) {
				T vertexLabel = vertex.first;
				int vertexDist = vertex.second;
				cout << "(" << vertexLabel << ", " << vertexDist << ")" << endl;
			}

			cout << endl;

			cout << "The length of the shortest path between " << 
			s << " and " << d << " : " << distanceMap[d] << endl;

			// for(pair<T, T> vertex : parentMap) {
			// 	T vertexLabel = vertex.first;
			// 	T parentLabel = vertex.second;
			// 	cout << "(" << vertexLabel << ", " << parentLabel << ")" << endl;
			// }

			// cout << endl;

			cout << "The shortest path between " << s << " and " << d << " : ";	
			T temp = d;
			while(parentMap[temp] != temp) {
				cout << temp << "<-";
				temp = parentMap[temp];
			}
			cout << temp << endl; // at this point temp is equal to source
		}

};


int main() {

	graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 6);
	g.addEdge(4, 6);
	g.addEdge(4, 7);
	g.addEdge(5, 7);
	g.addEdge(6, 8);
	g.addEdge(7, 8);

	g.print();

	g.bfs(0, 6);
	
	return 0;
}