#include <iostream>
#include "Header.hpp"

using namespace std;
class Solution {
	public:
		int findNthDigit(long long n) {
			vector<long long> level = {9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000};
			int i = 1;
			while (i <= 9 && n - (i) * level[i-1] > 0) {
			    n -= i * level[i-1];
			    i++;
			}
			int offset = (n+i-1) % (i);
			int diff = (n+i-1) / (i);
			int sum = 0;
			for (int j = 0; j < i-1; j++) sum += level[j];
			int target = sum + diff;
			string str_target = to_string(target);
			int res = str_target[i==1?0:offset] - '0';
			return res;
	}
};

using namespace std;
int main(int argc, char *argv[]) {
	Solution s;
	cout << s.findNthDigit(1000000000) << endl;
}