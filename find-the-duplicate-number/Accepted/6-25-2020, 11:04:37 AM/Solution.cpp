// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int L = 1; int R = nums.size() - 1; 
        int ans = R; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            int lt = 0; 
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= mid) {
                    ++lt; 
                }
            }
            
            if (lt > mid) {
                ans = mid; 
                R = mid - 1; 
            } else {
                L = mid + 1; 
            }
        }
        return ans; 
    }
};