/*

	Implementation of HashTable with key as a "string"

*/

#include<iostream>

using namespace std;

template <typename T1, typename T2>
class node {

public:
	T1 key;	
	T2 value;
	node<T1, T2>* next;

	node(T1 key, T2 value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

template <typename T1, typename T2>
class HashTable {
	int M; // to store the capacity of the hash table
	int N; // to store the size i.e. no. of key value pairs inside the hash table
	double LFT; // to store the load factor threshold
	node<T1, T2>** table; // to store the address of the dynamic array that represents the table

	int hash_fn(T1 key, int base=61) {
		int sum = 0;
		int power = 1;
		for(int i=0; i<key.size(); i++) {
			sum += (key[i]%M)*(power%M)%M;
			power = (power*base)%M;
		}
		return sum%M;
	}

	void transfer(node<T1, T2>* head) {
		node<T1, T2>* temp = head;
		while(temp) {
			insert(temp->key, temp->value);
			temp = temp->next;
		}

		// release the memory for the linked list at the ith index
		
		while(head) {
			node<T1, T2>* temp = head;
			head = head->next;
			delete temp;
		}

	}

	void rehash() {
		int oldM = M; // to store the current capacity 
		node<T1, T2>** oldTable = table; // to store address of current table

		// 1. create a new array with double capacity
		M = 2*M;
		table = new node<T1, T2>*[M];	
		for(int i=0; i<M; i++) {
			table[i] = NULL;
		}
		N = 0;

		// 2. transfer contents from the old array into the new array
		for(int i=0; i<oldM; i++) {
			transfer(oldTable[i]);
		}

		// 3. delete the old array
		delete [] oldTable;
	}

	public :

		HashTable(int M=5, double LFT=0.7) {
			this->M = M;
			this->LFT = LFT;
			this->N = 0;
			table = new node<T1, T2>*[M];	
			for(int i=0; i<M; i++) {
				table[i] = NULL;
			}
		} 

		void insert(T1 key, T2 value) {
			// 1. compute the hash index using the key
			int hash_idx = hash_fn(key);

			// 2. insert the (key, value) pair at the head of the LL at the hash index
			node<T1, T2>* n = new node<T1, T2>(key, value);
			n->next = table[hash_idx];
			table[hash_idx] = n;

			N++;

			// 3. rehash the HT, in case the load factor exceeds the load factor threshold
			double LF = N/(M*1.0);
			if(LF > LFT) {
				// rehash the HT
				cout << "load factor : " << LF << ", rehashing..." << endl;
				rehash();
			}
		}

		node<T1, T2>* find(T1 key) {
			// 1. compute the hash index for the given key
			int hash_idx = hash_fn(key);

			// 2. search for the key in the linked list at the hash_idx
			node<T1, T2>* temp = table[hash_idx];
			while(temp && temp->key != key) {
				temp = temp->next;
			}
			return temp;
		}

		void erase(T1 key) {
			// 1. compute the hash index corresponding to the key
			int hash_idx = hash_fn(key);

			// 2. delete the node with the given key, if present, from 
			//    the linked list at the hash index
			node<T1, T2>* prev = NULL;
			node<T1, T2>* temp = table[hash_idx];	
			if(temp->key == key) {
				// delete from the head of the linked list
				table[hash_idx] = temp->next;
				delete temp;
				N--;
			} else {
				// delete from non-head of the linked list
				while(temp) {
					if(temp->key == key) {
						prev->next = temp->next;
						delete temp;
						N--;
						break;
					}
					prev = temp;
					temp = temp->next;
				}
			}
		}

		void printLinkedList(node<T1, T2>* head) {
			while(head) {
				cout << "(" << head->key << ", " << head->value << ")";
				head = head->next;
				if(head) cout << "->"; 
			}
			cout << endl;
		}

		void print() {
			for(int i=0; i<M; i++) {
				cout << i << " : ";
				printLinkedList(table[i]);
			}
			cout << endl;
		}

		T2& operator[](T1 key) {
			node<T1, T2>* n = find(key);
			if(!n) {
				// key is not present inside the hash table
				T2 garbage;
				insert(key, garbage);
				n = find(key);
			}
			return n->value;
		}
};


int main() {

	HashTable<string, string> hashTable;

	hashTable.insert("abc", "word 1");
	hashTable.insert("def", "word 2");
	hashTable.insert("ghi", "word 3");

	hashTable.print();

	hashTable["jki"] = "word 4";

	hashTable.print();

	return 0;
	
}







