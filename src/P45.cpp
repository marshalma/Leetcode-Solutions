#include <iostream>
#include "Header.hpp"

using namespace std;

class Solution {
	public:
		int jump(vector<int>& nums) {
			int N = nums.size();
			if (N == 0) return 0;
			queue<int> positions;
			vector<bool> visited(nums.size(), false);
			positions.push(0);
			visited[0] = true;
			
			int step = 0;
			while(true) {
				int n = positions.size();
				step++;  
				for (int i = 0; i < n; i++) {
					int position = positions.front();
					positions.pop();
					for (int j = 1; j <= nums[position]; j++) {
						if (position+j >= nums.size()-1) return step;
						if (position+j < nums.size() && visited[position+j]) continue;
						positions.push(position+j);
						if (position+j < nums.size()) visited[position+j] = true;
					}
				}
			}
			//never reaches here
			return -1;
		}
	};
	
	
int main(int argc, char *argv[]) {
	Solution s;
	vector<int> test;
	for (int i = 25000; i>=1; i--) {
		test.push_back(i);
	}
	test.push_back(1);
	test.push_back(0);
	
	cout << s.jump(test);
}