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
            return schedule[a.first][a.second].start > schedule[b.first][b.second].start;    
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < schedule.size(); ++i) {
            if (schedule[i].empty()) continue;
            pq.push({i, 0});
        }
        
        auto get_next = [&]() -> Interval& {
            auto p = pq.top(); pq.pop();
            auto& ivl = schedule[p.first][p.second];
            if (p.second + 1 < schedule[p.first].size()) {
                pq.push({p.first, p.second+1});
            }
            return ivl;
        };
        
        Interval curr = get_next();
        vector<Interval> merged;
        int ext = 1;
        while(!pq.empty() || ext--) {
            if (!merged.empty() && merged.back().end >= curr.start) {
                merged.back().end = max(merged.back().end, curr.end);
            } else {
                merged.push_back(curr);
            }
            if (ext) {
                curr = get_next();
            }
        }
        vector<Interval> ans;
        for (int i = 0; i + 1 < merged.size(); ++i) {
            ans.push_back({merged[i].end, merged[i+1].start});
        }
        return ans;
    }
};