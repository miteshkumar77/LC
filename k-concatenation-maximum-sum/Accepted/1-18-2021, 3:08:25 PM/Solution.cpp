// https://leetcode.com/problems/k-concatenation-maximum-sum

class Solution {
public:
    typedef signed long long int ulli;
    int kConcatenationMaxSum(vector<int>& arr, ulli k) {
        ulli M = 1e9 + 7;
        ulli total = accumulate(arr.begin(), arr.end(), 0);
        ulli gmax = 0;
        ulli lmax = 0;
        ulli max_left = 0;
        ulli max_right = 0;
        ulli sum_left = 0;
        for (ulli i = 0; i < arr.size(); ++i) {
            lmax = max(lmax + arr[i], (ulli)arr[i]);
            sum_left += arr[i];
            max_right = max(max_right, total - sum_left + (ulli)arr[i]);
            max_left = max(max_left, sum_left);
            gmax = max(gmax, lmax);
        }
        

        if (k >= 2) {
            vector<ulli> results{
                total * k,
                max_right + max((k - 2) * total, (ulli)0) + max_left,
                gmax
            };
            
            return (*max_element(results.begin(), results.end())) % M;
        }
        return gmax % M;
        
        // if (k >= 2)
        //     // return max(total * k, max(max_right + max((k - 2) * total, 0) + max_left) + max_left, gmax); 
        //     return max((int)((total * k) % M) , max((int)(max_right + (max((k - 2) * total) % M), 0) + max_left, gmax)) % M;
        // else 
        //     return gmax; 
    }
};