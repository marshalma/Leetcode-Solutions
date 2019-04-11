#include <iostream>
#include "../Header.hpp"

using namespace std;

ostream& operator<< (ostream &out, const vector<vector<bool>>& toBePrint) {
	for (int i = 0; i < toBePrint.size(); i++) {
		for (int j = 0; j < toBePrint[0].size(); j++) {
			out << toBePrint[i][j] << ' ';
		}
		out << endl;
	}
	return out;
}

class Solution {
	public:
		
		
		bool isMatch(string s, string p) {
			if (s.size() == 0 && p.size() == 0) return true;
			if (s.size() > 0 && p.size() == 0) return false;
			
			// dptable[i][j] means the substring s[0:i] and substring p[0:j] is matched or not
			vector<bool> initvector(p.size()+1, false);
			vector<vector<bool>> dptable(s.size()+1, initvector);
			
			dptable[0][0] = true; // empty string matches empty string
			
			// initialization of the first row of the table
			for (int i = 1; i <= p.size(); i++) {
				if (p[i-1] == '*') dptable[0][i] = dptable[0][i-2];
				else dptable[0][i] = false;
			}
			
			for (int i = 1; i <= s.size(); i++) {
				dptable[i][0] = false;
			}
			
			for (int i = 0; i < s.size(); i++) {
				for (int j = 0; j < p.size(); j++) {
					if (p[j] == '.') {
						dptable[i+1][j+1] = dptable[i][j];
					}
					else if (p[j] == '*') {
						if (p[j-1] == '.') {
							dptable[i+1][j+1] = dptable[i][j+1] || dptable[i+1][j-1];
							// to do
						}
						else {
							if (s[i] == p[j-1]) {
								dptable[i+1][j+1] = dptable[i][j] || dptable[i+1][j-1] || dptable[i][j+1];
							}
							else {
								dptable[i+1][j+1] = dptable[i+1][j-1];
							}
						}
					}
					else {
						if (s[i] == p[j]) {
							dptable[i+1][j+1] = dptable[i][j];
						}
						else {
							dptable[i+1][j+1] = false;
						}
					}
					cout << i << ',' << j << ',' << endl << dptable << endl;
				}
			}
			
			
			return dptable[s.size()][p.size()];
			
		}
	};


int main(int argc, char *argv[]) {
	Solution s;
	bool res = s.isMatch("aaa", "ab*a*c*a");
	return 0;
}