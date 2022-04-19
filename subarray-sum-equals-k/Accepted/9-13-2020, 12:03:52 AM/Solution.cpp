// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ct{make_pair(0, 1)}; 
        int ans = 0; 
        int sum = 0; 
        for (int num : nums) {
            sum += num; 
            ans += ct[sum - k]; 
            ++ct[sum]; 
        }
        return ans; 
        
        
    }
};