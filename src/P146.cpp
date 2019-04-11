#include <iostream>
#include "Header.hpp"

using namespace std;

typedef pair<int, int> IntPair;

class LRUCache{
private:
	list<IntPair> ptList;
	unordered_map<int, list<IntPair>::iterator> table;
	int capacity;
	
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}
	
	int get(int key) {
		if (table.find(key) == table.end()) return -1;
		auto it = table[key];
		ptList.splice(ptList.begin(), ptList, it);
		table[key] = ptList.begin();
		return ptList.begin()->second;
	}
	
	void set(int key, int value) {
		if (this->table.find(key) != this->table.end()) {
			auto it = table[key];
			ptList.splice(ptList.begin(), ptList, it);
			ptList.begin()->second = value;
			table[key] = ptList.begin();
			return;
		}
		
		if (ptList.size() == capacity) {
			auto it = prev(ptList.end());
			table.erase(it->first);
			ptList.pop_back();
		}
		
		ptList.push_front(make_pair(key, value));
		table[key] = ptList.begin();
	}
};

int main() {
	LRUCache cache(5);
	cache.set(1,5);
	cache.set(2,5);
	cache.set(3,5);
	cache.set(4,5);
	cache.set(5,5);
	cache.set(1,4);
	cache.set(6,5);
	cache.set(100,5);
	cout << cache.get(3);
}