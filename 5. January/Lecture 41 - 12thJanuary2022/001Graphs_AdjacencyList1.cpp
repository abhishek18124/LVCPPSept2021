/*

Implementation of the graph using adjacency list.

Note : each vertex in the graph is an integer.

*/

#include<iostream>
#include<list>

using namespace std;

class graph {

	int V; // to store the no. of vertices present in the graph
	list<int>* arr; // to store the address of the dynamic array
	bool isDirected; // indicates if the graph is directed or not
	
	public :

		graph(int V, bool isDirected=false) {
			this->V = V;
			arr = new list<int>[V];
			this->isDirected = isDirected;
		}	

		void addEdge(int u, int v) {
			arr[u].push_back(v);
			if(!isDirected) {
				arr[v].push_back(u);	
			}
		}

		void print() {
			for(int i=0; i<V; i++) {
				cout << i << " : ";
				list<int> neighbourList = arr[i];
				for(int neighbour : neighbourList) {
					cout << neighbour << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

};

int main() {

	graph g(5);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);

	g.print();


	return 0;
}