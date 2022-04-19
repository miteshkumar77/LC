// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int L = 1; 
        int R = nums.size() - 1; 
        
        while(L <= R) {
            int mid = L + (R - L)/2; 
            
            int nums_below = 0; 
            int occurrences = 0; 
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == mid) {
                    ++occurrences; 
                    if (occurrences == 2) {
                        return mid; 
                    }
                    
                }
                
                if (nums[i] < mid) {
                    ++nums_below;
                }
            }
            
            if (nums_below < mid) {
                L = mid + 1; 
            } else {
                R = mid - 1; 
            }
        }
        
        return -1; 
    }
};