// https://leetcode.com/problems/max-chunks-to-make-sorted-ii

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffMin(n+1, INT_MAX);
        for (int i = n - 1; i >= 0; --i) {
            suffMin[i] = min(arr[i], suffMin[i+1]);
        }
        int mx = INT_MIN;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, arr[i]);
            if (mx <= suffMin[i+1]) {
                ++ans;
            }
        }
        return ans;
    }
};