#include "Header.hpp"

using namespace std;

class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			vector<vector<int>> res;
			
			for (int i = 0; i < nums.size(); i++) {
				int start = i+1, end = nums.size()-1;
				while (start < end) {
					cout << i << ',' << start << ',' << end << endl;
					if (nums[start] + nums[end] < -nums[i]) 
						while(start+1 < nums.size() && nums[start+1] == nums[start++]);
					else if (nums[start] + nums[end] > -nums[i]) 
						while(end-1 >= 0 && nums[end-1] == nums[end--]);
					else {
						res.push_back({nums[i], nums[start], nums[end]});
						while(start+1 < nums.size() && nums[start+1] == nums[start++]);
						while(end-1 >= 0 && nums[end-1] == nums[end--]);
					}
				}
				while (i+1 < nums.size() && nums[i+1] == nums[i]) i++;
			}
			
			return res;
		}
	};

int main(int argc, char *argv[]) {
	vector<int> v = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	Solution s;
	s.threeSum(v);
	return 0;
}