// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int curr; 
        int x = 0; 
        curr = nums[(x + k) % nums.size()]; 
        nums[(x + k) % nums.size()] = nums[x]; 
        x = (x + k) % nums.size(); 
        for (int i = 1; i < nums.size(); ++i) {
            swap(nums[(x + k) % nums.size()], curr); 
            x = (x + k) % nums.size();  
        }
        
    }
};