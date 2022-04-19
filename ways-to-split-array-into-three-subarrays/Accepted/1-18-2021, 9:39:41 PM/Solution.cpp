// https://leetcode.com/problems/ways-to-split-array-into-three-subarrays

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        
        int M = 1e9 + 7;
        
        for (int i = 1; i < nums.size(); ++i) pref[i] = nums[i] + pref[i - 1];
        
        int ans = 0;
        int left = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            left += nums[i];
            int l = i + 1;
            int r = n - 2;
            int lb = lower_bound(pref, l, r, left, left);
            int ub = upper_bound(pref, l, r, (nums.back() - left)/2, left);
            ans += max(0, ub - lb + 1);
            ans = ans % M;
        }
        return ans;
    }
    
    
    int lower_bound(const vector<int>& pref, int l, int r, int t, int left) {
        int ans = r + 1;
        int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (pref[mid] - left >= t) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    
    int upper_bound(const vector<int>& pref, int l, int r, int t, int left) {
        int ans = l - 1;
        int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (pref[mid] - left <= pref.back() - pref[mid]) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
    
    
};