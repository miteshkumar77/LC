// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return kth(nums, k); 
    }
    
    
    
    int kth(vector<int>& nums, int k) {
        int L = 0; 
        int R = nums.size() - 1; 
        while(L < R) {
            swap(nums[rand() % (R - L + 1) + L], nums[R]); 
            int mid = part(nums, L, R); 
            int count = R - mid + 1; 
            if (count == k) {
                return nums[mid]; 
            } else if (count > k) {
                L = mid + 1; 
            } else {
                R = mid - 1; 
                k = k - count; 
            }
        }
        
        return nums[L]; 
        
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