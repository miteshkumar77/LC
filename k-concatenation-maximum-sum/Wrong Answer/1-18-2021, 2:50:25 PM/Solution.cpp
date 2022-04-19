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
        
        return max(total * k, max(max_right + max(0, (max(0, k - 2) * total)) + max_left, gmax)); 
    }
};