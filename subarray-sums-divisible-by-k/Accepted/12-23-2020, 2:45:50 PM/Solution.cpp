// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    
    inline int mod(int n, int k) {
        return n < 0? (k - mod(-n, k))%k:n%k;
    }
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> seen(K, 0);
        int sum = 0;
        int ans = 0;
        seen[0] = 1;
        
        for (int i : A) {
            sum = mod(sum + i, K);
            
            ans += seen[sum];
            ++seen[sum];
        }
        
        return ans;

    }
};