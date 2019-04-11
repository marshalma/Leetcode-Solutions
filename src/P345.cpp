#include <iostream>
#include "Header.hpp"

using namespace std;
class Solution {
	public:
		string reverseVowels(string s) {
			vector<bool> vowel(256, false);
			vowel['a'] = true;
			vowel['e'] = true;
			vowel['i'] = true;
			vowel['o'] = true;
			vowel['u'] = true;
			vowel['A'] = true;
			vowel['E'] = true;
			vowel['I'] = true;
			vowel['O'] = true;
			vowel['U'] = true;
			int p1 = 0, p2 = s.size()-1;
			while (p1 < p2) {
				while (!vowel[s[p1]]) p1++;
				while (!vowel[s[p2]]) p2--;
				if (p1 >= p2) break;
				swap(s[p1], s[p2]);
				p1++;
				p2--;
			}
			return s;
		}
	};

using namespace std;
int main(int argc, char *argv[]) {
	Solution s;
	cout << s.reverseVowels(".,");
}