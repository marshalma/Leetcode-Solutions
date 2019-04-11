#include <iostream>
#include "Header.hpp"
using namespace std;

class Solution {
	public:
		bool isMatch(string s, string p) {
			int ss = 0, ps = 0, laststar = -1, sub_s = 0;
			
			while (ss < s.size()) {
				if (ps < p.size()) {
					if (s[ss] == p[ps] || p[ps] == '?') {
						ss++;
						ps++;
						continue;
					}
					
					if (p[ps] == '*') {
						laststar = ps++;
						sub_s = ss;
						continue;
					}
				}
				
				if (laststar >= 0) {
					ps = laststar + 1;
					ss = ++sub_s;
					continue;
				}
				
				return false;
			}
			
			while (ps < p.size() && p[ps] == '*') ps++;
			return ps == p.size();
		}
	};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.isMatch("aa", "*");
	return 0;
}