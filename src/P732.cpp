#include "../include/common.h"

class MyCalendarThree {
    vector<vector<int>> sorted_vec;
    int res = 0;
    
    int insert_helper(int start, int end) {
        int left = 0, right = sorted_vec.size() - 1;
        
        if (start >= end) return 0;
        
        // find the last element that is not greater than the element to be added.
        while (left < right) {
            int mid = (left + right + 1) / 2;
            
            if (sorted_vec[mid][0] < start) left = mid;
            else if (sorted_vec[mid][0] > start) right = mid - 1;
            else {
                left = mid;
                break;
            }
        }
        
        int pos = left;
        
        while (pos < sorted_vec.size()) { // always true
            cout << pos << ',' << sorted_vec.size() << ',' << start << ',' << end << ',' << sorted_vec[pos][0] << ',' << sorted_vec[pos][1] << endl;
            
            if (start >= sorted_vec[pos][1] && end <= sorted_vec[pos+1][0]) {
                cout << 'a' << endl;
                sorted_vec.insert(sorted_vec.begin()+pos+1, {start, end, 1});
                res = max(res, 1);
                return res;
            } else if (start >= sorted_vec[pos][1] && end > sorted_vec[pos+1][0]) {
                cout << 'b' << endl;
                int next_start = sorted_vec[pos+1][0];
                sorted_vec.insert(sorted_vec.begin()+pos+1, {start, sorted_vec[pos+1][0], 1});
                res = max(res, 1);
                start = next_start;
                pos++;pos++;
                continue;
            } else if (end > sorted_vec[pos][1]) {
                cout << 'c' << endl;
                int this_end = sorted_vec[pos][1];
                int conflicts = sorted_vec[pos][2];
                if (start == sorted_vec[pos][0]) {
                    sorted_vec[pos][2] = conflicts + 1;
                    res = max(res, sorted_vec[pos][2]);
                    start = sorted_vec[pos][1];
                    continue;
                } else {
                    sorted_vec[pos][1] = start;
                    sorted_vec.insert(sorted_vec.begin()+pos+1, {start, this_end, conflicts+1});
                    res = max(res, conflicts+1);
                    start = this_end;
                    pos++;
                    continue;
                }
            } else {
                cout << 'd' << endl;
                int this_end = sorted_vec[pos][1];
                int conflicts = sorted_vec[pos][2];
                if (start == sorted_vec[pos][0]) {
                    sorted_vec[pos][2] = conflicts + 1;
                    sorted_vec[pos][1] = end;
                    res = max(res, sorted_vec[pos][2]);
                    sorted_vec.insert(sorted_vec.begin()+pos+1, {end, this_end, conflicts});
                } else {
                    sorted_vec[pos][1] = start;
                    sorted_vec.insert(sorted_vec.begin()+pos+1, {start, end, conflicts+1});
                    res = max(res, conflicts+1);
                    sorted_vec.insert(sorted_vec.begin()+pos+2, {end, this_end, conflicts});
                }
                
                return res;
            }
        }
        
        return res;
    }
    
public:
    MyCalendarThree() {
        sorted_vec.push_back({-INT_MAX, -INT_MAX, 0});
        sorted_vec.push_back({INT_MAX, INT_MAX, 0});
    }
    
    int book(int start, int end) {
        cout << "---------" << endl;
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
	return 0;
}
