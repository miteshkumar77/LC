// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0; 
        int R = nums.size() - 1; 
        int ans = -1; 
        
        if (target > nums[R] && target < nums[L]) {
            return -1; 
        }
        
        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (nums[R] < nums[L]) {
                
                if (nums[mid] == target) {
                    return mid; 
                }
                
                if (nums[mid] > nums[L]) {
                    if (target > nums[mid] || target <= nums[R]) {
                        L = mid + 1; 
                    } else if (target < nums[mid] && target >= nums[L]) {
                        R = mid - 1; 
                    }
                } else { // nums[mid] < nums[R]
                    if (target > nums[mid] && target >= nums[L]) {
                        R = mid - 1; 
                    } else if (target > nums[mid] && target <= nums[R]) {
                        L = mid + 1; 
                    } else if (target < nums[mid]) {
                        R = mid - 1; 
                    }
                }
                
            } else {
                
                if (target > nums[mid]) {
                    L = mid + 1; 
                } else if (target < nums[mid]) {
                    R = mid - 1; 
                } else {
                    return mid; 
                }
            }
            
            cout << L << ", " << R << endl; 
        }
        
        
        
        return -1; 
    }
};