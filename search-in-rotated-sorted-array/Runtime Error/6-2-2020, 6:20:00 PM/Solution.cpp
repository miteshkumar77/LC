// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0; 
        int R = nums.size() - 1; 
        int mid;
        int ans = nums.size() - 1; 
        
        while(nums[L] > nums[R]) {
            mid = L + (R - L)/2; 
            cout << ans << endl; 
            if (nums[mid] >= nums[L]) {
                ans = mid; 
                L = mid + 1; 
            } else {
                ans = mid - 1; 
                R = mid - 1; 
            }
        }
        
        cout << ans << endl; 
        
        if (nums[0] <= target && target <= nums[ans]) {
            L = 0; 
            R = ans; 
        } else if (ans + 1 < nums.size() && nums[ans + 1] <= target && target <= nums.back()) {
            R = nums.size() - 1; 
            L = ans + 1; 
        } else {
            return -1; 
        }
        
        while(L <= R) {
            mid = L + (R - L)/2; 
            if (nums[mid] > target) {
                R = mid - 1; 
            } else if (nums[mid] < target) {
                L = mid + 1; 
            } else {
                ans = mid; 
                return mid; 
            }
        }
        return ans; 
    }
};