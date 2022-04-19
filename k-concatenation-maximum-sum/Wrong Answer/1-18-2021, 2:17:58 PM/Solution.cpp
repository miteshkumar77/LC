// https://leetcode.com/problems/k-concatenation-maximum-sum

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        
        int gmin = 0;
        int gmax = 0;
        int lmin = 0;
        int lmax = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            lmin = min(arr[i], lmin + arr[i]); 
            lmax = max(arr[i], lmax + arr[i]);
            gmin = min(gmin, lmin);
            gmax = max(gmax, lmax); 
        }
        
        if (k >= 2) {
            if (gmax > total - gmax) {
                return max(total * k, max(gmax, total - gmin)); 
            } else {
                return max(gmax, total - gmin); 
            }
        } else {
            return gmax;
        }
    }
};