// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition

class Solution {
public:
    typedef array<int, 2> pii; 
    int numSubseq(vector<int>& nums, int target) {
        int MOD = 1000000007; 
        sort(nums.begin(), nums.end()); 
        
        int L = 0; 
        int R = nums.size() - 1; 
        int ans = 0; 
        while(L <= R) {
            if (nums[L] + nums[R] <= target) {
                ans += (L < R)?((long long) pow(2, R - L) % MOD ):1; 
                ans %= MOD; 
                ++L; 
            } else {
                --R; 
            }
        }
        return ans; 
        
    }
};