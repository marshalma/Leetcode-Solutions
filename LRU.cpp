#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

class LRUCache{
	public:
		LRUCache(int capacity) {
			size = capacity;
		}
		
		int get(int key) {
			if (mapping.find(key) == mapping.end()) return -1;
			int res = (*mapping[key])._val;
			moveToMRU(mapping[key]);
			mapping[key] = ll.begin();
			return res;
		}
		
		void set(int key, int value) {
			if (mapping.find(key) != mapping.end()) {
				moveToMRU(mapping[key]);
				ll.front()._val = value;
				return;
			}
			if (mapping.size() == size) {
				mapping.erase(ll.back()._key);
				ll.pop_back();
			}
			ll.push_front(Node(value, key));
			mapping[key] = ll.begin();
		}
	private:
		struct Node{
			int _val;
			int _key;
			Node(int val, int key): _val(val), _key(key) {}
		};

		typedef list<Node>::iterator listit;
		unordered_map<int, listit> mapping;
		list<Node> ll;
		int size;
		
		void moveToMRU(listit it) {
			Node thisNode = *it;
			ll.erase(it);
			ll.push_front(thisNode);
		}
	};
int main(int argc, char *argv[]) {
	LRUCache cache(2);
	cache.set(1,2);
	cache.set(2,2);
	cache.set(3,3);
	cout << cache.get(1) << endl;
	cout << cache.get(3) << endl;
	return 0;
}