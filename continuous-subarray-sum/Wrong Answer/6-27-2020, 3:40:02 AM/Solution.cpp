// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mm; 
        if (k == 0) {
            return false; 
        }
        mm[0] = 0; 
        int sum = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            sum += i; 
            sum = sum % k; 
            if (mm.find(sum) != mm.end()) {
                if (i - mm[sum] + 1 >= 2) {
                    return true; 
                }
            } else {
                mm[sum] = i; 
            }
        }
        return false; 
    }
};