// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i = -1; 
        int majority_element = 0; 
        for (int num : nums) {
            if (i == -1) {
                i = 1; 
                majority_element = num; 
            } else {
                if (majority_element == num) {
                    ++i; 
                } else {
                    if (--i == 0) {
                        majority_element = num; 
                        i = 1; 
                    }
                }
            }
        }
        return majority_element; 
    }
};