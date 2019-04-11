#include <iostream>
#include "Header.hpp"

using namespace std;

class Solution {
	public:
		int square(int x) {return x*x;}
		int factorial(int x) {
			if (x == 0 || x == 1) return 1;
			else return x * factorial(x-1);
		}

		int numberOfBoomerangs(vector<pair<int, int>>& points) {
			unordered_map<int, int> counter;
			for (int i = 0; i < points.size(); i++) {
				for (int j = i+1; j < points.size(); i++) {
					int dist_2 = square(points[i].first - points[j].first) + square(points[i].second - points[j].second);
					counter[dist_2]++;
				}
			}
			int res = 0;
			for (auto it = counter.begin(); it != counter.end(); it++) {
				if (it->second == 1) continue;
				res += factorial(it->second) / factorial(it->second - 2);
			}
			return res;
		}
	};

using namespace std;
int main(int argc, char *argv[]) {
	Solution s;
	vector<pair<int, int>> tester = {make_pair(1,0),make_pair(0,0),make_pair(2,0)};
	cout << s.numberOfBoomerangs(tester);
}