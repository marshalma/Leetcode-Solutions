#include "Header.hpp"

using namespace std;

class Solution {
	struct Node{
		int len;
		int val;
		Node* next;
		Node* head;
		Node() : len(1), val(-1), next(nullptr), head(this) {}
	};
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end(), std::less<int>());
		if (nums.size() == 0) return {};
	    Node* dp = new Node[nums.size()];
	    dp[0].val = nums[0];
	    int maxLen = dp[0].len, maxIndex = 0;
	    for (int i = 1; i < nums.size(); i++) {
	        int _maxLen = INT_MIN, _maxIndex = -1;
	        for (int j = 0; j < i; j++) {
	            if (nums[i] % dp[j].val != 0) continue;
	            if (_maxLen < dp[j].len) {
	                _maxLen = dp[j].len;
	                _maxIndex = j;
	            }
	        }
	        if (_maxIndex == -1) dp[i].val = nums[i];
	        else {
	            dp[_maxIndex].next = &dp[i];
	            dp[i].val = nums[i];
	            dp[i].len = dp[_maxIndex].len+1;
	            dp[i].head = dp[_maxIndex].head;
	        }
	        if (maxLen < dp[i].len) {
	            maxLen = dp[i].len;
	            maxIndex = i;
	        }
	    }
	    
	    vector<int> ret;
	    Node* p = dp[maxIndex].head;
	    while(p) ret.push_back(p->val);
	    return ret;
		
	}
};

int main() {
	vector<int> v {1,2,3,4,8,9,16,26,27,81,162};
	Solution s;
	s.largestDivisibleSubset(v);
}