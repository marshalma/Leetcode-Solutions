#include "Header.hpp"

using namespace std;

class Solution {
	unordered_map<int, vector<vector<int>*>> mapping;
	bool acyclic = false;
public:
	bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
		for (auto &seq : seqs) {
			if (seq.size() == 0) continue;
			mapping[seq[0]].push_back(&seq);
		}
		
		unordered_set<int> history;
		if (mapping.find(org[0]) == mapping.end()) return false;
		history.insert(org[0]);
		for (auto v : mapping[org[0]]) {
			if (dfs(org, history, v, 0)) return true && !acyclic;
		}
		
		return false;
	}
	
	bool dfs(vector<int>& org, unordered_set<int>& history, vector<int>* thisSeq, int index) {
		if (org.size() == index) return true;
		for (int i = 1; i < thisSeq->size(); i++) {
		    if (history.find((*thisSeq)[i]) != history.end()) acyclic = true;
		}
		int i = 1;
		for (; i < thisSeq->size(); i++) {
			if (i + index >= org.size()) return false;
			if (org[i+index] != (*thisSeq)[i]) return false;
			if (mapping.find(org[i+index]) != mapping.end()) {
				history.insert(org[i+index]);
				for (auto v : mapping[org[i+index]]) {
					if (dfs(org, history, v, index+i)) return true;
				}
				history.erase(org[i+index]);
			}
		}
		return i+index == org.size() && org.back() == thisSeq->back();
	}
};

int main() {
	Solution s;
	vector<int> org = {1,2,3};
	vector<vector<int>> seqs = {vector<int>{1,2}, vector<int>{2,3}, vector<int>{3,1}};
	cout << s.sequenceReconstruction(org, seqs);
	return 0;
}