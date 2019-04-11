#include "Header.hpp"
#include <iostream>

using namespace std;

struct Interval {
	int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	struct Compare {
		bool operator()(Interval &i1, Interval &i2) {
			return i1.start < i2.start;
		}
	};
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() == 0) return vector<Interval>();
		cout << 1 << endl;
		sort(intervals.begin(), intervals.end(), Compare());
		vector<Interval> res;
		Interval this_interval = intervals[0];
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i].start > this_interval.end) {
				res.push_back(this_interval);
				this_interval = intervals[i];
				continue;
			}
			this_interval.end = max(this_interval.end, intervals[i].end);
		}
		res.push_back(this_interval);
		return res;
	}
};

using namespace std;
int main(int argc, char *argv[]) {
	vector<Interval> tester = {Interval(1,3),Interval(2,6),Interval(8,10),Interval(15,18),Interval(18,20)};
	Solution s;
	auto res = s.merge(tester);
	return 0;
}