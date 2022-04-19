// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1; 
        while(i >= 0 && digits[i] + 1 == 10) {
            digits[i] = 0; 
            i -= 1; 
        }
        if (i >= 0) {
            ++digits[i]; 
            return digits; 
        } else {
            vector<int> ans(digits.size() + 1); 
            ans[0] = 1; 
            for (int i = 0; i < digits.size(); ++i) {
                ans[i + 1] = digits[i]; 
            }
            return ans; 
        }
        
    }
};