// https://leetcode.com/problems/arithmetic-slices-ii-subsequence

class Solution {
public:
    typedef long long int lli; 
    int numberOfArithmeticSlices(vector<int>& nums) {
        // Write your code here
        int ans = 0; 
        vector<unordered_map<lli, array<lli, 2>>> dp(nums.size()); 
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                lli delta = (lli)nums[i] - nums[j];
                dp[i].insert(make_pair(delta, array<lli, 2>{0, 0})); 
                ++dp[i][delta][0]; 
                if (dp[j].find(delta) != dp[j].end()) {
                    dp[i][delta][1] += dp[j][delta][0] + dp[j][delta][1]; 
                }
            }
            for (auto p : dp[i]) ans += p.second[1]; 
        }
        return ans; 

    } 

};