#include "Header.hpp"

using namespace std;

void partial_sort(vector<int>& nums, int target) {
	int start = 0;
	int end = nums.size() - 1;
	
	//using first element as pivot.
	while (1) {
		if (target == start || target == end) return;
		
		int p = start + 1, q = end;
		while (p <= q) {
			if (nums[p] < nums[start]) p++;
			else swap(nums[p], nums[q--]);
		}
		swap(nums[p-1], nums[start]);
		
		
		if (target < p-1) {
			end = p - 2;
		}
		else if (target > p-1) {
			start = p;
			target -= start;
		}
		else return;
	}
}

int main(int argc, char *argv[]) {
	vector<int> v = {2,2,2,1,1,9,4,6,2,4};
	nth_element(v.begin(), v.begin() + (v.size()-1)/2, v.end());
	for (auto i : v) cout << i << endl;
	return 0;
}