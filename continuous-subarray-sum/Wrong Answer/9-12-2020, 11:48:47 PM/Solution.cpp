// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    
    
    inline int mod(int a, int b) {
        return (b == 0)?a:(a % b);     
    }
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        k = abs(k); 
        
        unordered_set<int> seen{0};
        int pref1 = mod(nums[0], k);  
        int pref2 = pref1; 
        for (int i = 1; i < nums.size(); ++i) {    
            pref2 = mod(pref2 + nums[i], k);  
            if (seen.find(mod(k - pref2 , k)) != seen.end()) {
                return true; 
            }
            seen.insert(pref1); 
            pref1 = pref2; 
        }
        return false; 
    }
};