// https://leetcode.com/problems/employee-free-time

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int n = schedule.size(); 
        vector<array<int, 2>> splitSchedule;
        splitSchedule.reserve(n<<1); 
        
        for (const vector<Interval>& v : schedule) {
            for (const Interval& i : v) {
                splitSchedule.push_back({i.start, 1});
                splitSchedule.push_back({i.end, -1});
            }
        }
        sort(splitSchedule.begin(), splitSchedule.end(), [](const array<int, 2>& a, const array<int, 2>& b) -> bool {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);  
        });
        
        int occupied = 0;
        vector<vector<int>> ans;
        for (const array<int, 2>& i : splitSchedule) {
            occupied += i[1];
            if (ans.size() != 0 && ans.back().size() == 1) {
                ans.back().push_back(i[0]); 
            } else if (occupied == 0) {
                ans.push_back(vector<int>{i[0]}); 
            }
        }
        if (ans.back().size() == 1) {
            ans.pop_back(); 
        }
        vector<Interval> ansv;
        ansv.reserve(ans.size());
        for (const vector<int>& a : ans) {
            ansv.push_back(Interval(a[0], a[1])); 
        }
        return ansv;
    }
};