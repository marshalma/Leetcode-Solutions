#include "../include/common.h"

class MyHashSet {
    struct Node {
        vector<int> chain;
    };
    
    Node hash_table[1000];
    
    int hash_fn(int v) {
        return ((v % 701) * (v % 401)) % 1000;
    }
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        // hash_table = (Node *)malloc(1000 * sizeof(Node));
        // cout << hash_table << endl;
    }
    
    void add(int key) {
        int hash_key = hash_fn(key);
        
        for (int i = 0; i < hash_table[hash_key].chain.size(); i++) {
            if (hash_table[hash_key].chain[i] == key) return;
        }
        
        hash_table[hash_key].chain.push_back(key);
    }
    
    void remove(int key) {
        int hash_key = hash_fn(key);
        
        for (int i = 0; i < hash_table[hash_key].chain.size(); i++) {
            if (hash_table[hash_key].chain[i] == key) {
                swap(hash_table[hash_key].chain[i], hash_table[hash_key].chain.back());
                hash_table[hash_key].chain.pop_back();
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash_key = hash_fn(key);
        
        for (int i = 0; i < hash_table[hash_key].chain.size(); i++) {
            if (hash_table[hash_key].chain[i] == key) return true;
        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
int main() {
	auto h = MyHashSet();

	h.add(1);

	return 0;
}
