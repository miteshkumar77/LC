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
            auto it2 = mp.find(i[1]); 
            
            if (it2 != mp.end()) {
                ans.push_back(it2 -> second); 
            } else if (it != mp.end()) {
                ans.push_back(it -> second); 
            } else {
                ans.push_back(-1); 
            }
        }
        return ans; 
    }
};