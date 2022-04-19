// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k + 1; 
        kth(nums, 0, nums.size() - 1, k); 
        return nums[k - 1]; 
    }
    
    
    
    void kth(vector<int>& nums, int L, int R, int k) {
        if (L == R) {
            return; 
        }
        
        swap(nums[rand() % (R - L + 1) + L], nums[R]); 
        int mid = part(nums, L, R); 
        
        if (mid + 1 == k) {
            return; 
        } else if (mid + 1 > k) {
            kth(nums, L, mid - 1, k); 
        } else {
            kth(nums, mid + 1, R, k - mid - 1); 
        }
    }
    
    
    int part(vector<int>& nums, int L, int R) {
        int i = L; 
        int p = nums[R]; 
        
        for (int j = L; j < R; ++j) {
            if (nums[j] <= p) {
                swap(nums[i++], nums[j]); 
            }
        }
        swap(nums[i], nums[R]); 
        return i; 
    }
    
    
    
    
    
    
};