// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums; 
        sums.insert(pair<int, int>(0, 1)); 
        int ans = 0;
        int cumulative_sum = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            cumulative_sum += nums[i];
            auto it = sums.find(cumulative_sum - k); ; 
            if (it != sums.end()) {
                ans += it -> second; 
            }
            it = sums.find(cumulative_sum);
            if (it == sums.end()) {
                sums.insert(pair<int, int> (cumulative_sum, 1)); 
            } else {
                ++(it -> second);
            }
        }
        return ans; 
        
    }
};