// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        
        if (arr.size() == 1) {
            return arr[0]; 
        }
        
        
        long long int max_rem = INT_MIN; 
        long long int max_nrem = arr[0]; 
        
        long long int gmax = max(max_rem, max_nrem); 
        
        for (int i = 1; i < arr.size(); ++i) {
            max_rem = max(max_rem + arr[i], max_nrem); 
            max_nrem = max((long long)(max_nrem + arr[i]), (long long)arr[i]); 
            gmax = max(gmax, max(max_nrem, max_rem)); 
        }

        return gmax; 
    }
};