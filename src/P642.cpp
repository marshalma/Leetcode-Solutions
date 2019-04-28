#include "../include/common.h"

class AutocompleteSystem {
    struct Comparator {
        bool operator()(const pair<string, int> &a, const pair<string, int> &b) const{
            if (a.second == b.second) {
                return a.first.compare(b.first);
            }
            return a.second > b.second;
        }
    };
    
    struct Node {
        char ch;
        multiset<pair<string, int>, Comparator> mapping;
        unordered_map<string, multiset<pair<string, int>, Comparator>::iterator> mapping2;
        unordered_map<char, Node*> children;
        
        Node() {}
        
        Node(char ch) {
            this->ch = ch;
        }
    };
    
    Node node;
    string cur_sen;
    Node *cur_node = NULL;
    
    void insert_sentence(Node *a, string &sentence, int idx, int times) {
        if (idx == sentence.size()) return;
        
        Node *new_node;
        if (a->children.count(sentence[idx]) == 0) {
            new_node= new Node(sentence[idx]);
            //cout << sentence[idx] << endl;
            a->children[sentence[idx]] = new_node;
        } else {
            new_node = a->children[sentence[idx]];
        }   
        
        insert_sentence(new_node, sentence, idx+1, times);
        
        if (a->mapping2.count(sentence) == 0) {
            auto it = a->mapping.insert(make_pair(sentence, times));
            a->mapping2[sentence] = it;
        } else {
            int history = a->mapping2[sentence]->second;
            history += times;
            a->mapping.erase(a->mapping2[sentence]);
            auto it = a->mapping.insert(make_pair(sentence, history));
            a->mapping2[sentence] = it;
        }
    }
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        Node *p = &node;
        for (int i = 0; i < sentences.size(); i++) {
            //cout << sentences[i] << endl;
            insert_sentence(p, sentences[i], 0, times[i]);
        }
        cur_node = &node;
        //cout << cur_node->children['i']->mapping.begin()->second << endl;
        //cout << cur_node->children.size() << endl;
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            insert_sentence(&node, cur_sen, 0, 1);
            cur_node = &node;
            cur_sen.clear();
            return {};
        }
        
        cur_sen.push_back(c);
        
        bool found = false;
        for (auto p: cur_node->children) {
            if (p.first == c) {
                cur_node = p.second;
                found = true;
                break;
            }
        }
        
        if (!found) return {};
        
        auto mapping = cur_node->mapping;
        vector<string> res;
        auto it = mapping.begin();
        for (int i = 0; i < 3; i++) {
            //cout << i << endl;
            if (it == mapping.end()) break;
            
            res.push_back(it->first);
            it++;
        }
        
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */


int main() {
	vector<string> input1 = {"i love you","island","iroman","i love leetcode"};
	vector<int> input2 = {5, 3, 2, 2};

	AutocompleteSystem s(input1, input2);
	vector<string> output;
    output = s.input('i');
    for (auto s: output) cout << s << endl;
	output = s.input(' ');
    for (auto s: output) cout << s << endl;
	output = s.input('a');
    for (auto s: output) cout << s << endl;
	output = s.input('#');
    for (auto s: output) cout << s << endl;
	output = s.input('i');
    for (auto s: output) cout << s << endl;
	output = s.input(' ');
    for (auto s: output) cout << s << endl;
	output = s.input('a');
    for (auto s: output) cout << s << endl;
	output = s.input('#');
    for (auto s: output) cout << s << endl;
	output = s.input('i');
    for (auto s: output) cout << s << endl;
	output = s.input(' ');
    for (auto s: output) cout << s << endl;
	output = s.input('a');
    for (auto s: output) cout << s << endl;
	output = s.input('#');
    for (auto s: output) cout << s << endl;

	return 0;
}	
