// https://leetcode.com/problems/rotate-array

class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {
        int iterations; 
        int n = nums.size(); 
        if (k % nums.size() == 0) {
            return; 
        }
        if (nums.size() % k == 0) {
            iterations = k;
        } else {
            iterations = 1; 
        }
        int curr;
        int x; 
        for (int i = 0; i < iterations; ++i) {
            
            curr = nums[i]; 
            x = (i + k) % n; 
            while(x != i) {
                swap(nums[x], curr); 
                x = (x + k) % n; 
            }
            swap(nums[x], curr); 
        }
        
    }
    
    
    
};