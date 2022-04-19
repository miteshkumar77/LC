// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> intervals; 
        unordered_set<int> ns (nums.begin(), nums.end()); 
        for (int n : ns) {
            bool found_neg = intervals.find(n - 1) != intervals.end(); 
            bool found_pos = intervals.find(n + 1) != intervals.end(); 
            
            if (!found_neg && !found_pos) {
                intervals[n] = n; 
            } else if (found_neg && !found_pos) {
                intervals[n] = intervals[n - 1]; 
                intervals.erase(n - 1);
                intervals[intervals[n]] = n; 
            } else if (!found_neg && found_pos) {
                intervals[n] = intervals[n + 1]; 
                intervals.erase(n + 1);
                intervals[intervals[n]] = n; 
            } else {
                int start = intervals[n - 1]; 
                int end = intervals[n + 1]; 
                intervals.erase(n - 1); 
                intervals.erase(n + 1); 
                intervals.erase(start); 
                intervals.erase(end); 
                intervals[start] = end; 
                intervals[end] = start; 
            }
            
            
        }
        
        int ans = 0; 
        for (auto it : intervals) {
            ans = max(ans, 1 + it.second - it.first); 
        }
        return ans; 
            
    }
};