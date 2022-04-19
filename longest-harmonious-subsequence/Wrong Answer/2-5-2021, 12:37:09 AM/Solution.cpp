// https://leetcode.com/problems/longest-harmonious-subsequence

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> ct;
        int ans = 0;
        int tmp = 0;
        for (int i : nums) {
            tmp = 0;
            for (int d = -1; d <= 1; ++d) {
                if (ct.count(i + d)) {
                    tmp = max(tmp, ct[i + d]); 
                }
            }
            ++tmp;
            ans = max(ans, tmp);
            if (!ct.count(i)) {
                ct[i] = tmp;
            }
            ct[i] = max(ct[i], tmp); 
        }
        return ans;
    }
};