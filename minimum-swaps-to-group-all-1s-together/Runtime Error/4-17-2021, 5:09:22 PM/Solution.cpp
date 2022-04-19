// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        int num_ones = 0;
        for (int i : data) {
            num_ones += i;
        }
        int window = 0;
        int ans = INT_MAX;
        for (int i = 0; i + 1 < num_ones; ++i) {
            window += data[i];   
        }
        for (int i = num_ones - 1; i < n; ++i) {
            window += data[i];
            ans = min(ans, num_ones - window);
            window -= data[i + 1 - num_ones];
        }
        return ans;
    }
};