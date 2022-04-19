// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition

class Solution {
public:
    
    int exp(int b, int exponent, int MOD) {
        
        int result = 1; 
        unsigned long long int base = b % MOD; 
        while(exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % MOD; 
            }
            exponent = exponent >> 1; 
            base = (base * base) % MOD; 
        }
        return result; 
    }
    
    int numSubseq(vector<int>& nums, int target) {
        int MOD = 1000000007; 
        sort(nums.begin(), nums.end()); 
        
        int L = 0; 
        int R = nums.size() - 1; 
        int ans = 0; 
        while(L <= R) {
            if (nums[L] + nums[R] <= target) {
                ans += (L < R)?(exp(2, R - L, MOD)):1; 
                ans %= MOD; 
                ++L; 
            } else {
                --R; 
            }
        }
        return ans; 
        
    }
};