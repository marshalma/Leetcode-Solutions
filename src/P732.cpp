#include "../include/common.h"

class MyCalendarThree {
    map<int, vector<int>> mapp;
    int res = 0;
    
    int insert_helper(int start, int end) {        
        if (start >= end) return 0;
        
        // find the last element that is not greater than the element to be added.
        auto pos = mapp.lower_bound(start);
        
        while (pos != mapp.end()) { // always true
//            cout << pos << ',' << sorted_vec.size() << ',' << start << ',' << end << ',' << sorted_vec[pos][0] << ',' << sorted_vec[pos][1] << endl;
            
            if (start >= pos->second[0] && end <= next(pos)->first) {
//                cout << 'a' << endl;
                mapp[start] = {end, 1});
                res = max(res, 1);
                return res;
            } else if (start >= pos->second[0] && end > next(pos)->first) {
//                cout << 'b' << endl;
                int next_start = next(pos)->first;
                mapp[start] = {*next(pos)->first, 1};
                res = max(res, 1);
                start = next_start;
                pos++;pos++;
                continue;
            } else if (end > pos->second[0]) {
//                cout << 'c' << endl;
                int this_end = pos->second[0];
                int conflicts = pos->second[1];
                if (start == pos->first) {
                    pos->second[1] = conflicts + 1;
                    res = max(res, pos->second[1]);
                    start = pos->second[0];
                    continue;
                } else {
                    pos->second[0] = start;
                    mapp[start] = {this_end, conflicts+1};
                    res = max(res, conflicts+1);
                    start = this_end;
                    pos++;
                    continue;
                }
            } else {
//                cout << 'd' << endl;
                int this_end = pos->second[0];
                int conflicts = pos->second[1];
                if (start == pos->first) {
                    pos->second[1] = conflicts + 1;
                    pos->second[0] = end;
                    res = max(res, pos->second[1]);
                    mapp[end] = this_end, conflicts};
                } else {
                    pos->second[0] = start;
                    mapp[start] = {end, conflicts+1};
                    res = max(res, conflicts+1);
                    mapp[end] = {this_end, conflicts};
                }
                
                return res;
            }
        }
        
        return res;
    }
    
public:
    MyCalendarThree() {
        mapp[-INT_MAX] = {-INT_MAX, 0});
        mapp[INT_MAX] = {INT_MAX, 0});
    }
    
    int book(int start, int end) {
//        cout << "---------" << endl;
        insert_helper(start, end);
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

int main() {
    vector<vector<int>> calls = {{35,49},{27,41},{65,78},{52,69},{95,100},{58,73},{45,60},{47,64},{40,53},{73,91},{91,100},{26,42},{8,22},{96,100},{38,51},{39,49},{93,100},{21,36},{54,69},{68,83},{61,75},{40,56},{99,100},{46,64},{32,47},{91,100},{29,42},{10,27},{77,89},{75,87},{62,81},{4,19},{11,27},{4,16},{61,78},{25,37},{15,30},{74,89},{83,95},{0,16},{36,46},{90,100},{96,100},{57,70},{13,31},{68,80},{37,54},{30,47},{21,32},{69,84},{66,83},{20,37},{74,93},{29,39},{36,49},{15,33},{12,29},{8,27},{67,84},{18,37}};
    
    MyCalendarThree s;
    
    for (int i = 0; i < calls.size(); i++) {
        s.book(calls[i][0], calls[i][1]);
    }
    
	return 0;
}
