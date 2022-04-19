// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int T) {
        int n = arr.size();
        int prefix = 0;
        unordered_map<int,int> seen;
        seen[0] = -1;
        vector<int> dp(n, INT_MAX);
        int ans = INT_MAX;
        for (int i = 0; i < arr.size(); ++i) {
            prefix += arr[i];
            if (seen.find(prefix - T) != seen.end()) {
                int lastIdx = seen[prefix - T];
                int len = i - lastIdx;
                
                dp[i] = min(i >= 1?dp[i - 1]:INT_MAX, len);
                if (lastIdx >= 0) {
                    ans = min(ans, dp[lastIdx] == INT_MAX?INT_MAX:len + dp[lastIdx]);
                }
            } else {
                dp[i] = i >= 1?dp[i - 1]:INT_MAX;
            }
            seen[prefix] = i;
        }
        
        return ans == INT_MAX?-1:ans;
    }
};