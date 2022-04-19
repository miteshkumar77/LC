// https://leetcode.com/problems/k-concatenation-maximum-sum

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        int gmax = 0;
        int lmax = 0;
        int max_left = 0;
        int max_right = 0;
        int sum_left = 0;
        for (int i = 0; i < arr.size(); ++i) {
            lmax = max(lmax + arr[i], arr[i]);
            sum_left += arr[i];
            max_right = max(max_right, total - sum_left + arr[i]);
            max_left = max(max_left, sum_left);
            gmax = max(gmax, lmax);
        }
        if (k >= 2)
            // return max(total * k, max(max_right + max((k - 2) * total, 0) + max_left) + max_left, gmax); 
            return max(total * k, max(max_right + max((k - 2) * total, 0) + max_left, gmax));
        else 
            return gmax; 
    }
};