// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k); 
    }
    
    
    int quickSelect(vector<int>& nums, int L, int R, int k) {
        int pivot = L; 
        swap(nums[pivot], nums[rand() % (R - L + 1) + L]); 
        for (int j = L; j < R; ++j) {
            if (nums[j] <= nums[R]) {
                swap(nums[pivot++], nums[j]); 
            }
        }
        
        swap(nums[pivot], nums[R]);
        
        int ct = R - pivot + 1; 
        
        if (ct == k) {
            return nums[pivot]; 
        }
        
        if (ct > k) {
            return quickSelect(nums, pivot + 1, R, k); 
        }
        
        return quickSelect(nums, L, pivot - 1, k - ct); 
    }
    
    
    
    
    
};