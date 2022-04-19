// https://leetcode.com/problems/missing-ranges

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> intervals;
        int prev = lower - 1;
        for (int i : nums) {
            if (prev < i - 1) {
                int s = prev + 1;
                int e = i - 1;
                if (s != e) {
                    intervals.push_back(to_string(s) + "->" + to_string(e));
                } else {
                    intervals.push_back(to_string(s));
                }
            }
            prev = i; 
        }
        int s = prev + 1;
        int e = upper;
        if (s != e) {
            intervals.push_back(to_string(s) + "->" + to_string(e));
        } else {
            intervals.push_back(to_string(s));
        }
        return intervals;
    }
};