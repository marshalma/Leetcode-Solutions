#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		void reverseWords(string &s) {
			reverse(s.begin(), s.end());
			int last_begin = 0;
			for (int i = 1; i < s.size(); i++) {
				if (s[i] == ' ') {
					reverse(s.begin() + last_begin, s.begin() + i);
					last_begin = i + 1;
				}
			}
			reverse(s.begin() + last_begin, s.end());
		}
	};
	
int main() {
	Solution s;
	string a = "this is a nice day";
	s.reverseWords(a);
	cout << a << endl;
}