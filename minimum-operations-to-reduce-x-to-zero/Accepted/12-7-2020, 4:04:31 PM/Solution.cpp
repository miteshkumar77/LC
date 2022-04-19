// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for (int i : nums) total += i;
        
        int j = 0; 
        int window = 0;
        int ans = INT_MIN;
        // total - window = x
        
        for (int i = 0; i < n; ++i) {
            window += nums[i];
            while(j <= i && total - window < x) {
                window -= nums[j++];
            }
            if (total - window == x) {
                ans = max(ans, i - j + 1);
            }
        }
        
        return ans == INT_MIN?-1:n-ans;
    }
};