// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq(nums.begin(), nums.end());
        int gans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            
            if (seq.find(nums[i]) != seq.end()) {
                int ans = 1;
                int f = nums[i] + 1;
                while(seq.find(f) != seq.end()) {
                    
                    ++ans;
                    seq.erase(f++);
                }
                int b = nums[i] - 1;
                while(seq.find(b) != seq.end()) {
                    ++ans;
                    seq.erase(b--);
                }
                gans = max(gans, ans);
            }
        }
        return gans;
    }
};