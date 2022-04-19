// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int T) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        int ans = INT_MAX;
        int sum = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            while(sum > T) {
                sum -= arr[j++];
            }
            if (sum == T) {
                dp[i] = min(i==0?INT_MAX:dp[i - 1], i - j + 1);
                if (j != 0 && dp[j - 1] != INT_MAX) {
                    ans = min(ans, i - j + 1 + dp[j - 1]); 
                }
            } else {
                dp[i] = i==0?INT_MAX:dp[i - 1];
            }
        }
        // for (int i : dp) cout << i << ' ';
        // cout << endl;
        return ans==INT_MAX?-1:ans;
        
    }
};