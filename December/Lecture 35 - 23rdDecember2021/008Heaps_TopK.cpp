/*

Given an infinite stream of non-negative integers, design an algorithm to output the 
top-K integers every time you encounter -1.

Example : Input = 4, 1, 2, -1, 3, -1 7 0 1 2 -1 8 -1 . . . ; K = 3
          Output = 1 2 4
                   2 3 4
                   3 4 7
                   4 7 8
                   . . .

*/

#include<iostream>
#include<queue>

using namespace std;

void printMinHeap(priority_queue<int, vector<int>, greater<int>> minHeap) {
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {

    int k;
    cin >> k;

    int x; // to read value from the stream

    priority_queue<int, vector<int>, greater<int>> minHeap;

    // build a minHeap using the first k values read from the 
    // stream, assume you'll not get a -1 till you've read
    // atleast k values from the stream

    for(int i=0; i<k; i++) {
        cin >> x;
        minHeap.push(x);
    }

    while(true) {
        cin >> x;
        if(x == -1) {
            // print the top-k elements you've read
            printMinHeap(minHeap);
        } else {
            // check if the x is greater than min. of top-k you've read
            if(x > minHeap.top()) {
                minHeap.pop();
                minHeap.push(x);
            }
        }
    }

    return 0;

}