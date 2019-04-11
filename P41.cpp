#include <iostream>
#include "Header.hpp"

using namespace std;

int firstMissingPositive(vector<int>& nums) {
	if (!nums.size()) return 1;
	for (int i = 0; i < nums.size(); i++) {
	    if (nums[i] <= 0 || nums[i] > nums.size()) continue;
	    if (nums[nums[i]-1] == nums[i]) continue;
		int val = nums[i];
	    while (val > 0 && val <= nums.size()) {
			int tmp_val = nums[val-1];
			if (tmp_val == val) break;
			nums[val-1] = val;
			val = tmp_val;
	    }
	}
	for (int i = 0; i < nums.size(); i++) {
	    if (nums[i] != i+1) return i+1;
	}
	return nums.size()+1;
}

using namespace std;
int main(int argc, char *argv[]) {
	vector<int> test {2,1};
	cout << firstMissingPositive(test);
}