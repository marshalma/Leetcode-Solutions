#include <iostream>
#include "../include/common.h"
using namespace std;

class Solution {
	static bool isdigit(char ch) {
		return ch >= '0' && ch <= '9';
	}
	
	string decode_helper(string s, int &idx) {
		string res;
		
		while (idx < s.size() && s[idx] != ']') {
			while (idx < s.size() && !isdigit(s[idx])) {
				if (s[idx] == ']') {
					idx++;
					return res;
				}

				res.push_back(s[idx++]);
			}

			int multiplier = 0;
			cout << multiplier << endl;
			while (idx < s.size() && isdigit(s[idx])) {
				multiplier = multiplier * 10 + s[idx++] - '0';
			}

			// skip '['
			string subres = decode_helper(s, ++idx);
			for (int i = 0; i < multiplier; i++) {
				res.append(subres);
			}

			if (idx < s.size() && s[idx] == ']') {
				idx++;
			}
			
		}
		return res;
	}
	
public:
	string decodeString(string s) {
		string res;
		int i = 0;
		
		res = decode_helper(s, i);
		
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	
	cout << s.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef") << endl;
	
	return 0;
}