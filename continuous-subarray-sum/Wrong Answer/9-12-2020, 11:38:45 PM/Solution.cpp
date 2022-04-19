// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        
        
        unordered_set<int> seen{0};
        int pref1 = (k == 0)?nums[0]:nums[0] % k; 
        int pref2 = pref1; 
        for (int i = 1; i < nums.size(); ++i) {
            pref2 = pref2 + nums[i];
    
            pref2 = (k == 0)?pref2:pref2 % k; 
            if (seen.find(k - pref2) != seen.end()) {
                return true; 
            }
            seen.insert(pref1); 
            pref1 = pref2; 
        }
        return false; 
    }
};