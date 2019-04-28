#include <iostream>
#include "Header.hpp"
using namespace std;

class MyCalendarTwo {
	map<int, int> level1;
	map<int, int> level2;
	
	bool book_internal(int start, int end) {
		auto lower_bound = level2.lower_bound(start);
		
		if (lower_bound != level2.begin()) {
			int floor_val = prev(lower_bound)->second;
			if (floor_val > start) return false;
		}
		
		if (lower_bound != level2.end()) {
			int ceil_key = lower_bound->first;
			if (ceil_key < end) return false;
		}
		
		level2[start] = end;
		return true;
	}
	
public:
	MyCalendarTwo() {
		
	}
	
	bool book(int start, int end) {
		auto lower_bound = level1.lower_bound(start);
		auto it = make_reverse_iterator(prev(lower_bound));
		
		if (it != level1.rend()) {
			if (it->second > start) {
				bool subres = book_internal(start, it->second);
				if (subres) {
					level1[it->second] = min(lower_bound != level1.end() ? lower_bound->first : INT_MAX, end);
					return true;
				} else {
					return false;
				}
			}
		}
		
		while (lower_bound != level1.end()) {
			if (start >= end) break;
			
			if (lower_bound->first < end) {
				bool subres = book_internal(lower_bound->first, min(end, lower_bound->second));
				if (subres) {
					level1[start] = min(end, lower_bound->second);
					start = lower_bound->second;
					continue;
				} else {
					return false;
				}
			}
		}
		
		
		if (start < end)
			level1[start] = end;
		return true;
	}
};

int main(int argc, char *argv[]) {
	
}