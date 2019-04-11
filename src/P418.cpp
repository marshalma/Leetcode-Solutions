#include <iostream>
#include "Header.hpp"

using namespace std;

class Solution {
	public:
		int wordsTyping(vector<string>& sentence, int rows, int cols) {
			int count = 0;
			int i = 0;
			int len = sentence.size();
			unordered_map<int, pair<int, int>> table;
			while (i < rows) {
				int remain = cols;
				
				if (table.find(count % len) != table.end()) {
					const auto& lastResult = table[count % len];
					int incrementCount = count - lastResult.first;
					int incrementRow = i - lastResult.second;
					if (i + incrementRow < rows) {
						
						table[count % len] = make_pair(count, i);
						i += incrementRow;
						count += incrementCount;
						cout << "-" << endl;
						continue;
					}
				}
				table[count % len] = make_pair(count, i);
				while (remain >= (int)sentence[count % len].size()) {
					remain -= sentence[count % len].size() + 1;
					count++;
				}
				i++;
			}
			return count / sentence.size();
		}
	};


int main(int argc, char *argv[]) {
	Solution s;
	vector<string> a {"I", "had", "apple", "pie"};
	cout << s.wordsTyping(a, 400, 5) << endl;
}