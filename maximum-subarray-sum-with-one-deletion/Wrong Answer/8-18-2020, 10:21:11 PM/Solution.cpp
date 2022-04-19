// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        
        if (arr.size() == 1) {
            return arr[0]; 
        }
        
        int max_rem = max(arr[0], arr[1]); 
        
        int max_nrem = max(arr[1], arr[0] + arr[1]); 
        int gmax = max(max_rem, max_nrem); 
        
        
        
        for (int i = 2; i < arr.size(); ++i) {
            max_rem = max(max_rem + arr[i], max(max_nrem, arr[i]));
            max_nrem = max(max_nrem + arr[i], max_nrem); 
            gmax = max(max_rem, max(gmax, max_nrem)); 
        }
        return gmax; 
    }
};