// https://leetcode.com/problems/max-chunks-to-make-sorted

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(arr[i], mx);
            ans += (i == mx);
        }
        return ans;
    }
};