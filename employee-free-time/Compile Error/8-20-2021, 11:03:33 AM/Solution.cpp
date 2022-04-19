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
        auto cmp = [&](pair<int,int> const& a, pair<int,int> const& b) -> bool {
            return schedule[a.first][a.second].start < schedule[b.first][b.second].start;    
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < schedule.size(); ++i) {
            if (schedule[i].empty()) continue;
            pq.push({i, 0});
        }
        
        auto get_next = [&]() -> Interval& {
            auto p = pq.top();
            auto& ivl = schedule[p.first][p.second];
            if (p.second + 1 < schedule[p.first].size()) {
                pq.emplace({p.first, p.second-1});
            }
            return ivl;
        };
        
        Interval curr = get_next();
        return {curr};
    }
};