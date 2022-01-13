/*

Computing SSSP using the Dijkstra's algorithm in a weighted graph.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<list>
#include<climits>
#include<unordered_set>
#include<set>

using namespace std;

template <typename T>
class graph {
	map<T, list<pair<T, int>>> neighbourMap;
	bool isDirected;

	public :

		graph(bool isDirected=false) {
			this->isDirected = isDirected;
		}

		void addEdge(T u, T v, int w) {
			neighbourMap[u].push_back({v, w});
			if(!isDirected) {
				neighbourMap[v].push_back({u, w});
			}
		}

		void print() {
			for(pair<T, list<pair<T, int>>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<pair<T, int>> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(pair<T, int> neighbour : neighbourList) {
					T neighbourLabel = neighbour.first;
					int edgeWeight = neighbour.second;
					cout << "(" << neighbourLabel << ", " << edgeWeight << ") ";
				}
				cout << endl;
			}
			cout << endl;
		}

		void dijkstra(T s, T d) {

			map<T, int> distanceMap;
			for(auto vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				distanceMap[vertexLabel] = INT_MAX;
			}

			distanceMap[s] = 0; // shortest dist of 's' from itself is 0

			unordered_set<T> explored; // to store vertices whose shortest dist. from the
								       // source has been computed and all the tensed edges
								       // have been relaxed

			set<pair<int, T>> minHeap; // to store the unexplored vertices
			for(pair<T, int> vertex : distanceMap) {
				T vertexLabel  = vertex.first;
				int vertexDist = vertex.second;
				minHeap.insert({vertexDist, vertexLabel});
			}

			map<T, T> parentMap;
			parentMap[s] = s;

			while(!minHeap.empty()) {
				pair<int, T> minVertex = *(minHeap.begin());
				minHeap.erase(minHeap.begin());

				int minVertexDist = minVertex.first;
				T minVertexLabel  = minVertex.second;

				list<pair<T, int>> neighbourList = neighbourMap[minVertexLabel];
				for(pair<T, int> neighbour : neighbourList) {
					T neighbourLabel = neighbour.first;
					int edgeWeight = neighbour.second;
					if(explored.find(neighbourLabel) == explored.end() && 
						distanceMap[neighbourLabel] > distanceMap[minVertexLabel] + edgeWeight) {

						// relax the edge between minVertexLabel & neighbourLabel

						// update the distance of the neighbourLabel in the minHeap
						auto it = minHeap.find({distanceMap[neighbourLabel], neighbourLabel});
						minHeap.erase(it);
						minHeap.insert({distanceMap[minVertexLabel] + edgeWeight, neighbourLabel});

						// update the distance of the neighbourLabel in the distanceMap
						distanceMap[neighbourLabel] = distanceMap[minVertexLabel] + edgeWeight;
						
						// update the parent of neighbourLabel
						parentMap[neighbourLabel] = minVertexLabel;
					}
				}

				explored.insert(minVertexLabel);
			}

			for(pair<T, int> vertex : distanceMap) {
				T vertexLabel = vertex.first;
				int vertexDist = vertex.second;
				cout << "(" << vertexLabel << ", " << vertexDist << ")" << endl;
			}

			cout << endl;

			cout << "The length of the shortest path between " << 
			s << " and " << d << " : " << distanceMap[d] << endl;


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

	graph<char> g;

	g.addEdge('A', 'B', 10);
	g.addEdge('A', 'C', 5);
	g.addEdge('B', 'C', 3);
	g.addEdge('B', 'D', 1);
	g.addEdge('C', 'D', 9);
	g.addEdge('C', 'E', 2);
	g.addEdge('D', 'E', 8);

	g.print();

	g.dijkstra('A', 'D');

	return 0;
}