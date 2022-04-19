// https://leetcode.com/problems/find-right-interval

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> mp; 
        for (int i = 0; i < intervals.size(); ++i) {
            mp[intervals[i][0]] = i; 
        }
        
        vector<int> ans; ans.reserve(intervals.size()); 
        for (vector<int> i : intervals) {
            auto it = mp.upper_bound(i[1]); 
            if (it == mp.end()) {
                if (prev(it) -> first < i[1]) {
                    ans.push_back(-1); 
                } else {
                    ans.push_back(prev(it) -> second); 
                }
            } else {
                ans.push_back(it -> second); 
            }
        }
        return ans; 
    }
};