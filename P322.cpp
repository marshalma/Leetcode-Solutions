#include "Header.hpp"

using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		static vector<int> dp{0};
		unordered_set<int> den(coins.begin(), coins.end());
		for (int i = dp.size(); i <= amount; i++) {
			int tmp = INT_MAX;
			for (int j = 0; j < i; j++) {
				if (den.find(i-j) == den.end()) continue;
				if (dp[j] == -1) continue;
				tmp = min(tmp, dp[j] + 1);
			}
			if (tmp == INT_MAX) dp.push_back(-1);
			else dp.push_back(tmp);
		}
		
		return dp[amount];
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> vec {2};
	cout << s.coinChange(vec, 1);
}