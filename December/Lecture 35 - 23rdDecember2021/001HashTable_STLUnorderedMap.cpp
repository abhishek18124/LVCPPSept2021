/*

What are unordered maps ? 

Unordered maps are associative containers that store elements formed by the combination of a 
key value and a mapped value, and which allows for fast retrieval of individual elements based 
on their keys. 

No two elements in the container can have equivalent keys.

What is the meaning of associative container ? 

Elements in associative containers are referenced by their key and not by their absolute 
position in the container.

How to create an unordered_map ? 
	> use empty container constructor (default constructor)
	> use initialiser list (C++11)
	> use copy constructor
	> use range constructor
How to insert (K, V) pair into an unordered_map ?
	> use unordered_map::insert (C++11)
    > use []
How to update a (K, V) pair in an unordered_map ?
    > use [] 
How to lookup/search for the value corresponding to a key in an unordered_map ? 
    > use unordered_map::find
    > use unordered_map::count
    > use []
How to delete a (K, V) pair from an unordered_map ?
	> use unordered_map::erase
	  > by key
	  > by position
	  > by range
    > use unordered_map::clear to remove all the elements from an unordered_map
How to check size of an unordered_map ?
	> use unordered_map::size to know number of (K, V) pairs present in an unordered_map
How to check number of buckets in an unordered_map ?
	> use unordered_map::bucket_count to know number of buckets present in an unordered_map
How to check if a unordered_map is empty ?
    > use unordered_map::empty or check if size of unordered_map is 0
How to iterate over elements in an unordered_map ?
    > use an iterator

*/

#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	// build an unordered_map using the default constructor
	unordered_map<string, string> captilMap;
	
	// inserting into a map

	// using unordered_map::insert
	captilMap.insert(make_pair("India", "New Delhi"));
	captilMap.insert({"USA", "Washington"});

	// using []
	captilMap["France"] = "Paris";

	// print map size using unordered_map::size
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

	// using an iterator to iterate over buckets
	for(int i=0; i<captilMap.bucket_count(); i++) {
		cout << i << " : ";
		for(auto it=captilMap.begin(i), end=captilMap.end(i); it != end; it++) {
			cout << "(" << it->first << ", " << it->second << ") ";
		}
		cout << endl;
	}

	cout << endl;

	// updating a value corresponding to a key in a map using []
	captilMap["India"] = "Delhi";

	for(auto p : captilMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	// lookups

	// using unordered_map::find
	string key = "Japan";
	if(captilMap.find(key) != captilMap.end()) {
		cout << "(" << key << ", " << captilMap[key] << ")" << endl; 
	} else {
		cout << key << " not found!" << endl;
	}

	// using unordered_map::count

	key = "India";
	if(captilMap.count(key)) {
		cout << "(" << key << ", " << captilMap[key] << ")" << endl; 
	} else {
		cout << key << " not found!" << endl;
	}
	
	// deletion using unordered_map::erase

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

	// clear using unordered_map::clear

	captilMap.clear();

	cout << "size : " << captilMap.size() << endl;

	// build an unordered_map using the initialiser list

	unordered_map<int, int> squareMap = {{1, 1},
										 {2, 4},
										 {3, 9},
										 {4, 16}};


	for(auto p : squareMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	return 0;
}