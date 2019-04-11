#include "../Header.hpp"

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		// Let's assume that words is not empty
		int N = words.size();
		int n = words[0].size();
		
		vector<vector<int>> match(n, vector<int>());
		unordered_map<string, vector<int>> table_index;
		unordered_map<int, int> table_num;
		
		for (int i = 0; i < words.size(); i++) {
			table_index[words[i]].push_back(i);
			table_num[table_index[words[i]][0]]++;
		}
		
		for (int i = 0; i <= (int)s.size() - n; i++) {
			string substring = s.substr(i, n);
			if (table_index.find(substring) == table_index.end()) {
				match[i % n].push_back(-1);
			}
			else {
				match[i % n].push_back(table_index[substring][0]);
			}
		}
		
		vector<int> res;
		unordered_map<int, int> mapping;
		int total = 0;
		for (int j = 0; j < match.size(); j++) {
			int p1 = 0;
			mapping.clear(); // words index to number of this word
			total = 0;
			const auto& vec = match[j];
			for (int i = 0; i < vec.size(); i++) {
				if (vec[i] == -1) {
					p1 = i+1;
					mapping.clear();
					total = 0;
				}
				else if (mapping.find(vec[i]) != mapping.end() && mapping[vec[i]] == table_num[vec[i]]) {
					int duplicate = vec[i];
					while (p1 < vec.size() && vec[p1] != duplicate) {
						int test = --mapping[vec[p1]];
						total--;
						if (test == 0) mapping.erase(vec[p1]);
						p1++;
					}
					p1++;
				}
				else {
					mapping[vec[i]]++;
					total++;
				}
				
				if (total == N) res.push_back(j + p1 * n);
			}
		}
		
		return res;
	}
};


int main() {
	Solution s;
	vector<string> words = {"mississippi"};
	auto res = s.findSubstring("mississippis", words);
	cout << res[0];
	return 0;
}