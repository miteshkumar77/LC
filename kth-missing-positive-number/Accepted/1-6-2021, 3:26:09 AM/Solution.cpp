// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 0;
        for (int i = 1; i <= INT_MAX; ++i) {
            if (j < arr.size() && arr[j] == i) {
                ++j;
            } else {
                --k;
            }
            if (k == 0) {
                return i;
            }
        }
        return -1;
    }
};