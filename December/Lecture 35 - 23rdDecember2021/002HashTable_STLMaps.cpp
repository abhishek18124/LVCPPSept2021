/*

What are maps ? 

Maps are associative containers that store elements formed by a combination of a key value 
and a mapped value, following a specific order. Internally, the elements in a map are always 
sorted by its key.

Maps are typically implemented as binary search trees, and therefore are generally slower 
than unordered_map containers to access individual elements by their key.

How to create an map ? 
	> use empty container constructor (default constructor)
	> use initialiser list (C++11)
	> use copy constructor
	> use range constructor
How to insert (K, V) pair into an map ?
	> use map::insert (C++11)
    > use []
How to update a (K, V) pair in an map ?
    > use [] 
How to lookup/search for the value corresponding to a key in an map ? 
    > use map::find
    > use map::count
    > use []
How to delete a (K, V) pair from an map ?
	> use map::erase
	  > by key
	  > by position
	  > by range
    > use map::clear to remove all the elements from an map
How to check size of an map ?
	> use map::size to know number of (K, V) pairs present in an map
How to check if a map is empty ?
    > use map::empty or check if size of map is 0
How to iterate over elements in an map ?
    > use an iterator

*/

#include<iostream>
#include<map>

using namespace std;

int main() {

	// build an map using the default constructor
	map<string, string> captilMap;
	
	// inserting into a map

	// using map::insert
	captilMap.insert(make_pair("India", "New Delhi"));
	captilMap.insert({"USA", "Washington"});

	// using []
	captilMap["France"] = "Paris";

	// print map size using map::size
	cout << "size : " << captilMap.size() << endl; 

	cout << endl;

	// iterating over the map

	// using an iterator
	for(auto it=captilMap.begin(), end=captilMap.end(); it != end; it++) {
		// pair<string, string> p = *it;
		// cout << p.first << " " << p.second << endl;
		
		// cout << (*it).first << " " << (*it).second << endl;

		cout << "(" << it->first << ", " << it->second << ")" << endl;
	}

	cout << endl;

	// using for-each loop

	for(auto p : captilMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	// updating a value corresponding to a key in a map using []
	captilMap["India"] = "Delhi";

	for(auto p : captilMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	// lookups

	// using map::find
	string key = "Japan";
	if(captilMap.find(key) != captilMap.end()) {
		cout << "(" << key << ", " << captilMap[key] << ")" << endl; 
	} else {
		cout << key << " not found!" << endl;
	}

	// using map::count

	key = "India";
	if(captilMap.count(key)) {
		cout << "(" << key << ", " << captilMap[key] << ")" << endl; 
	} else {
		cout << key << " not found!" << endl;
	}
	
	// deletion using map::erase

	// by key

	cout << endl;

	key = "France";
	captilMap.erase(key);

	for(auto p : captilMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	if(captilMap.count(key)) {
		cout << "(" << key << ", " << captilMap[key] << ")" << endl; 
	} else {
		cout << key << " not found!" << endl;
	}

	// clear using map::clear

	captilMap.clear();

	cout << "size : " << captilMap.size() << endl;

	// build an map using the initialiser list

	map<int, int> squareMap = {{4, 1},
							   {1, 4},
							   {3, 9},
							   {2, 16}};


	for(auto p : squareMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	return 0;

	return 0;
}