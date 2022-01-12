/*

    Given k sorted arrays, merge them and print the sorted output.

    k = 3
    Input : {
                {1, 3, 5, 7}, 
                {2, 4, 6, 8}, 
                {0, 9, 10, 11}
            }

    Output: 0 1 2 3 4 5 6 7 8 9 10 11 

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// class Triple {
// public:
//     int val;
//     int arr_idx;
//     int val_idx;

//     Triple(int val, int arr_idx, int val_idx) {
//         this->val = val;
//         this->arr_idx = arr_idx;
//         this->val_idx = val_idx;
//     }
// };

// class TripleCompare {
// public:
//     bool operator()(Triple t1, Triple t2) const {
//         return t1.val > t2.val;
//     }

// };

int main() {

    vector<vector<int>> v = {{1, 3, 5, 7}, 
                             {2, 4, 6, 8}, 
                             {0, 9, 10, 11}};

    int k = v.size();

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

    for(int arr_idx=0; arr_idx<k; arr_idx++) {
        int val = v[arr_idx][0];
        int val_idx = 0;
        minHeap.push({val, arr_idx, val_idx});
    }

    vector<int> result;
    while(!minHeap.empty()) {
        vector<int> minNode = minHeap.top();
        minHeap.pop();

        int val = minNode[0];
        int arr_idx = minNode[1];
        int val_idx = minNode[2];

        result.push_back(val);

        if(val_idx+1 < v[arr_idx].size()) {

           minHeap.push({v[arr_idx][val_idx+1], 
                         arr_idx, 
                         val_idx+1});
        }

    }

    for(auto x : result) {
        cout << x << " ";
    }





    return 0;

}