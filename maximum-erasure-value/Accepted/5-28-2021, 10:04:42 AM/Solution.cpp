// https://leetcode.com/problems/maximum-erasure-value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        int j = 0;
        unordered_map<int,int> ct;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            ++ct[nums[i]];
            while(ct[nums[i]] > 1) {
                --ct[nums[j]];
                sum -= nums[j++];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};