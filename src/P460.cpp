#include <iostream>
#include "../include/common.h"
using namespace std;

class LFUCache {
	struct freq_node;
	
	struct entry_node {
		int val;
		list<freq_node>::iterator parent_iter;
		
		entry_node(int val): val(val) {}
	};
	
	struct freq_node {
		int freq;
		list<entry_node> entry_list;
		
		freq_node(int freq): freq(freq) {}
	};
	
	int capacity;
	int size;
	list<freq_node> freq_list;
	unordered_map<int, list<entry_node>::iterator> mapping;
	
	void increment_freq(int key, int value) {
		auto iter = mapping[key];
		struct entry_node enode(value);
		
		auto parent_iter = iter->parent_iter;
		parent_iter->entry_list.erase(iter);
		
		auto parent_next_iter = next(parent_iter);
		if (parent_next_iter->freq == parent_iter->freq + 1) {
			parent_next_iter->entry_list.push_back(enode);
		} else {
			struct freq_node fnode(parent_iter->freq + 1);
			parent_next_iter = freq_list.insert(parent_next_iter, fnode);
			parent_next_iter->entry_list.push_back(enode);
		}
		
		if (parent_iter->entry_list.size() == 0) {
			freq_list.erase(parent_iter);
		}
	}
	
public:
	LFUCache(int capacity) {
		this->capacity = capacity;
		this->size = 0;
	}
	
	int get(int key) {
		if (mapping.count(key) == 0) {
			return -1;
		}
		
		auto iter = mapping[key];
		int value = iter->val;
		
		increment_freq(key, value);
		
		return value;
	}
	
	void put(int key, int value) {
		if (capacity == 0) return;
		
		size++;
		
		if (mapping.count(key) != 0) {
			increment_freq(key, value);
			return;
		}
		
		while (size > capacity) {
			// remove least frequent unit
			auto iter = freq_list.begin()->entry_list.begin();
			auto parent_iter = iter->parent_iter;
			
			parent_iter->entry_list.erase(iter);
			if (parent_iter->entry_list.size() == 0) {
				freq_list.erase(parent_iter);
			}
			mapping.erase(key);
			size--;
		}
		
		struct entry_node enode(value);
		if (freq_list.size() == 0 || freq_list.begin()->freq > 1) {
			struct freq_node fnode(1);
			freq_list.push_front(fnode);
			enode.parent_iter = freq_list.begin();
			auto flist = freq_list.begin();
			flist->entry_list.push_back(enode);
			freq_list.begin();
		} else {
			auto parent_iter = freq_list.begin();
			enode.parent_iter = freq_list.begin();
			parent_iter->entry_list.push_back(enode);
		}
		mapping[key] = prev(freq_list.begin()->entry_list.end());
	}
};

int main(int argc, char *argv[]) {
	LFUCache c(2);
	c.put(1,1);
	c.put(2,2);
	cout << c.get(1) << endl;
	c.put(3,3);
	cout << c.get(2) << endl;
	cout << c.get(3) << endl;
	c.put(4,4);
	cout << c.get(1) << endl;
	cout << c.get(3) << endl;
	cout << c.get(4) << endl;
	
	return 0;
}