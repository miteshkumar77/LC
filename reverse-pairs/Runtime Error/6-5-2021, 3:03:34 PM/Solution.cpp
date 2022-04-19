// https://leetcode.com/problems/reverse-pairs

class Solution {
public:
    void get(int l, int r, vector<int>& nums, vector<int>& swp, int n, int& ans) {
        if (l >= r) return;
        int mid = l + (r - l)/2;
        get(l, mid, nums, swp, n, ans); get(mid+1, r, nums, swp, n, ans);
        int j = r;
        int i;
        for (i = mid; i >= l; --i) {
            while(j > mid && nums[i] <= 2 * nums[j]) --j;
            ans += (j - mid);
        }
        i = l;
        j = mid+1;
        for (int x = l; x <= r; ++x) {
            if (i > mid || (j <= r && nums[j] <= nums[i])) {
                swp[x] = nums[j++];
            } else {
                swp[x] = nums[i++];
            }
        }
        for (int x = l; x <= r; ++x) {
            nums[x] = swp[x];
        }
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> swp(n);
        get(0, n-1, nums, swp, n, ans);
        return ans;
    }
};