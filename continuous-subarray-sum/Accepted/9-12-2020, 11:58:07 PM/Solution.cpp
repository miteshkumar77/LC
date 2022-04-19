// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    
    int mod(int a, int b) {
        return b == 0?a:a%b; 
    }
    
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_set<int> seen{0}; 
        int p1 = mod(nums[0], k); 
        int p2 = p1; 
        for (int i = 1; i < nums.size(); ++i) {
            p2 = mod(p2 + nums[i], k); 
            if (seen.find(p2) != seen.end()) {
                return true; 
            }
            
            seen.insert(p1); 
            p1 = p2; 
        }
        return false; 
    }
};