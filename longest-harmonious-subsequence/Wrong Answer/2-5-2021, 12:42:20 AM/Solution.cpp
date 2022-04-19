// https://leetcode.com/problems/longest-harmonious-subsequence

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> ct;
        int ans = 0;
        int tmp;
        for (int i : nums) {
            tmp = 1;
            if (!ct.count(i - 2)) continue;
            for (int d = i-1; d <= i+1; ++d) {
                if (ct.count(d)) {
                    tmp += ct[d];
                }
            }
            ans = max(ans, tmp); 
            ++ct[i];
        }
        return ans;
    }
};