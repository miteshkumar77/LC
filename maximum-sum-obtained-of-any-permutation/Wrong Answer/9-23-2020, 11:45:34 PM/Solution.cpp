// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size(); 
        vector<int> lazy(n + 1, 0); 
        for (auto v : requests) {
            lazy[v[0]] += 1; 
            lazy[v[1] + 1] -= 1; 
        }

        for (int i = 1; i < n; ++i) {
            lazy[i] += lazy[i - 1]; 
        }
        sort(nums.begin(), nums.end()); 
        sort(lazy.begin(), lazy.end()); 
        int ans = 0;
        int M = 1e9 + 7; 
        for (int i = 0; i < n; ++i) {
            ans = (ans + lazy[i] * nums[i]) % M; 
        }
        return ans;  
    }
};