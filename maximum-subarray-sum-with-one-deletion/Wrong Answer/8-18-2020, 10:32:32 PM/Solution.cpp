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
            max_nrem = max((unsigned long long)(max_nrem + arr[i]), (unsigned long long)arr[i]); 
            gmax = max(gmax, max(max_nrem, max_rem)); 
        }
//         int max_rem = max(arr[0], arr[1]); 
        
//         int max_nrem = max(arr[1], arr[0] + arr[1]); 
//         int gmax = max(max_rem, max_nrem); 
        
        
        
//         for (int i = 2; i < arr.size(); ++i) {
//             max_rem = max(max_rem + arr[i], max(max_nrem, arr[i]));
//             max_nrem = max(max_nrem + arr[i], max_nrem); 
//             cout << max_rem << ' ' << max_nrem << endl; 
//             gmax = max(max_rem, max(gmax, max_nrem)); 
//         }
        return gmax; 
    }
};