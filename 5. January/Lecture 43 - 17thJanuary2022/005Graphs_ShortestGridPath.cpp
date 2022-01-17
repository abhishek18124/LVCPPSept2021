/*
	
	Given a matrix of dimension m x n in which each cell contains an integer denoting
	the cost to traverse through the cell, design an algorithm to compute the sum of
	numbers along the minimum sum path from the top-left cell to the bottom-right cell.

	Assume there does not exist any negative cost cycles in the given matrix.

*/

#include<iostream>
#include<vector>
#include<set>
#include<climits>

using namespace std;

int shortestPath(vector<vector<int>> grid, int m, int n) {

	vector<vector<int>> distanceMap(m, vector<int>(n, INT_MAX));

	// to reach the source vertex i.e. the cell at top-left corner
	// we incur a cost of grid[0][0]
	distanceMap[0][0] = grid[0][0]; 

	vector<vector<bool>> explored(m, vector<bool>(n, false));

	// each entry in the minHeap is pair composed of tentative distance
	// of the vertex (i, j) from the source vertex and vertex label (i, j).
	set<pair<int, pair<int, int>>> minHeap;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			minHeap.insert({
								distanceMap[i][j], 
					            {i, j}
					       });
		}
	}

	int d_x[4] = {1, -1, 0, 0};
	int d_y[4] = {0, 0, 1, -1};

	while(!minHeap.empty()) {
		pair<int, pair<int, int>> minVertex = *(minHeap.begin());
		minHeap.erase(minHeap.begin());

		int minVertexDistance = minVertex.first;
		int minVertex_x = minVertex.second.first; // ith idx of the extracted vertex
		int minVertex_y = minVertex.second.second;// jth idx of the extracted vertex

		for(int k=0; k<4; k++) {
			int n_x = minVertex_x + d_x[k];
			int n_y = minVertex_y + d_y[k];

			if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n && !explored[n_x][n_y] && 
			   distanceMap[n_x][n_y] > minVertexDistance + grid[n_x][n_y]) {
				// relax the directed edge between minVertex and neighbour

				// update the tentative distance of the neighbour in the minHeap
				auto it = minHeap.find({ distanceMap[n_x][n_y], 
					                     {n_x, n_y}
					                   });
			    minHeap.erase(it);
			    minHeap.insert({  minVertexDistance + grid[n_x][n_y], 
			                      {n_x, n_y}
			                   });

				// update the tentaitve distance of the neighbour in the distanceMap
				distanceMap[n_x][n_y] = minVertexDistance + grid[n_x][n_y];

			}
		}

		explored[minVertex_x][minVertex_y] = true;

	}

	// return shortest distance of the destination i.e. the cell at the 
	// bottom-right corner at index (m-1, n-1) 
	return distanceMap[m-1][n-1];

}

int main() {

	vector<vector<int>> grid = {{31,  100, 65,  12,  18},
                                {10,  13,  47,  157, 6},
                                {100, 113, 174, 11,  33},
                                {88,  124, 41,  20,  140},
                                {99,  32,  111, 41,  20}};

    int m = grid.size();
    int n = grid[0].size();

    cout << shortestPath(grid, m, n) << endl;

    return 0;
}