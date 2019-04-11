#include <iostream>
#include "Header.hpp"
using namespace std;


class Solution {
public:
	int numSquares(int n) {
		static std::vector<int> dp_array;
		int last_n = (int)dp_array.size()-1;
		if (n <= last_n) return dp_array[n];
		
		dp_array.resize(n+1);
		for (int i = last_n+1; i < n+1; i++) dp_array[i] = INT_MAX;
		for (int i = (int)sqrt(last_n); i*i < n+1; i++) {
			dp_array[i*i] = 1;
		}
		for (int i = last_n+1; i < n+1; i++) {
			for (int j = 1; j < i; j++) {
				dp_array[i] = std::min(dp_array[i], dp_array[j] + dp_array[i-j]);
			}
		}
		return dp_array[n];
	}
};


int main(int argc, char *argv[]) {
	Solution s;
	cout << s.numSquares(125);
	return 0;
}