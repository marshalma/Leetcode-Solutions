#include <iostream>

class Solution {
	public:
		vector<vector<int>> getFactors(int n) {
			vector<vector<int>> res;
			for (int i = (int)sqrt(n); i > 1; i--) {
				if (n % i != 0) continue;
				vector<vector<int>> subres = getFactors(n / i);
				for (auto& v : subres) {
					if (i < v.back()) continue;
					v.push_back(i);
					res.push_back(v);
				}
				res.push_back({i, n/i});
			}
			return res;
		}
	};
	

using namespace std;
int main(int argc, char *argv[]) {
	Solution s;
	s.getFactors(24);
	return 0;
}