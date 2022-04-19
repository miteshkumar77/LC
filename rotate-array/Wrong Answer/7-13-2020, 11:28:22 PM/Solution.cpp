// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int curr; 
        int x = 0; 
        if (nums.size() % k == 0) {
            return; 
        }
        
        curr = nums[x]; 
        for (int i = 0; i < nums.size(); ++i) {
            swap(nums[x], curr); 
            x = (x + k) % nums.size(); 
        }
        swap(nums[x], curr); 
        
    }
};