// https://leetcode.com/problems/k-concatenation-maximum-sum

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        
        int gmin = 0;
        int gmax = 0;
        int lenmin = 1;
        int lenmax = 1;
        int lmin = arr[0];
        int lmax = arr[0];
        int llenmin = 1;
        int llenmax = 1;
        
        for (int i = 1; i < arr.size(); ++i) {
            if (lmin + arr[i] <= arr[i]) {
                lmin += arr[i];
                ++lenmin;
            } else {
                lmin = arr[i];
                lenmin = 1;
            }
            
            if (lmax + arr[i] >= arr[i]) {
                lmax += arr[i];
                ++lenmax;
            } else {
                lenmax = arr[i];
                lenmax = 1;
            }
            
            llenmax = max(lenmax, llenmax);
            llenmin = min(llenmin, lenmin);
            gmin = min(gmin, lmin);
            gmax = max(gmax, lmax);
        }
        
        if (lenmax == arr.size()) {
            return max(total - gmin, k * gmax); 
        } else {
            return max(total - gmin, gmax); 
        }
    }
};