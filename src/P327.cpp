#include "Header.hpp"

using namespace std;

class Solution {
	public:
		int countRangeSum(vector<int>& nums, int lower, int upper) {
			vector<long long> nums64(nums.size(), 0);
			for (int i = 0; i < nums64.size(); i++) {
				if (i == 0) nums64[i] = nums[0];
				else nums64[i] = (long long)nums[i] + nums64[i-1];
			}
			
			return mergeSortWhileCount(nums64, 0, nums.size()-1, lower, upper);
		}
		
		int mergeSortWhileCount(vector<long long>& nums, int start, int end, int lower, int upper) {
			if (end < start) return 0;
			if (end == start) return lower <= nums[start] && nums[start] <= upper;
			
			int mid = (start+end)/2;
			int leftres = mergeSortWhileCount(nums, start, mid, lower, upper);
			int rightres = mergeSortWhileCount(nums, mid+1, end, lower, upper);
			int res = leftres + rightres;
			
			vector<long long> arranged(end-start+1, 0);
			int p21 = mid+1, p22 = mid+1;
			for (int i = start; i <= mid; i++) {
				while (p21 <= end && nums[p21] - nums[i] < lower) p21++;
				while (p22 <= end && nums[p22] - nums[i] <= upper) p22++;
				res += p22-p21;
			}
			
			int idx = 0, p1 = start, p2 = mid+1;
			while (true) {
				while ((p2 > end && p1 <= mid) || (p1 <= mid && nums[p1] < nums[p2])) arranged[idx++] = nums[p1++];
				while ((p1 > mid && p2 <= end) || (p2 <= end && nums[p2] <= nums[p1])) arranged[idx++] = nums[p2++];
				if (p1 > mid && p2 > end) break;
			}
			
			for (int i = start; i <= end; i++) {
				nums[i] = arranged[i-start];
			}
			
			return res;
		}
	};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> nums {-2147483647,0,-2147483647,2147483647};
	cout << s.countRangeSum(nums, -564, 3864) << endl;
}