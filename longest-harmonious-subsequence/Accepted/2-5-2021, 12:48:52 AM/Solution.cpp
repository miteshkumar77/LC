// https://leetcode.com/problems/longest-harmonious-subsequence

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> ct;
        int ans = 0;
        int tmp;
        for (int i : nums) {
            ++ct[i];

            if (ct.count(i - 1)) {
                ans = max(ans, ct[i - 1] + ct[i]);
            }
            if (ct.count(i + 1)) {
                ans = max(ans, ct[i + 1] + ct[i]); 
            }
        }
        return ans;
    }
};