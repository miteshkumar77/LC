// https://leetcode.com/problems/reverse-pairs

class Solution {
public:
    vector<array<int, 2>> swp;
    vector<array<int, 2>> ans;
    int n;
    int mid;
    int i, j, k;
    void get(int l, int r) {
        if (l >= r) return;
        mid = l + (r - l)/2;
        get(l, mid); get(mid+1, r);
        i = l;
        for (j = mid + 1; j <= r; ++j) {
            while(i <= mid && 2 * ans[i][0] < ans[j][0]) ++i;
            ans[j][1] += i-l;
        }
        k = 0;
        i = l; j = mid + 1;
        while(i <= mid || j <= r) {
            if (i > mid || (j <= r && ans[i][0] >= ans[j][0])) {
                swp[k++] = ans[j++];
            } else {
                swp[k++] = ans[i++];
            }
        }
        for (int i = l; i <= r; ++i) {
            ans[i] = swp[i-l];
        }
    }
    
    int reversePairs(vector<int>& nums) {
        n = nums.size();
        reverse(nums.begin(), nums.end());
        swp = vector<array<int, 2>>(n, {0, 0});
        ans = vector<array<int, 2>>(n, {0, 0});
        for (int i = 0; i < n; ++i) {
            ans[i][0] = nums[i];
        }
        int a = 0;
        get(0, n-1);
        for (int i = 0; i < n; ++i) {
            a += ans[i][1];
        }
        return a;
    }
};