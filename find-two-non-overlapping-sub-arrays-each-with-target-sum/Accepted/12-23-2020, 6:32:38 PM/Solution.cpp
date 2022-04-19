// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int T) {
        int n = arr.size();
        // i > j
        // p[i] - p[j] = T
        // p[j] = p[i] - T
        vector<int> dp(n, INT_MAX);
        int prev = INT_MAX;
        unordered_map<int,int> seen;
        seen[0] = -1;
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (seen.find(sum - T) != seen.end()) {
                dp[i] = min(prev, i - seen[sum - T]); 
            } else {
                dp[i] = prev;
            }
            prev = dp[i];
            seen[sum] = i;
        }
        
        // for (int i : dp) cout << i << ' ';
        // cout << endl;
        
        seen = unordered_map<int,int>();
        int ans = INT_MAX;
        sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (seen.find(sum - T) != seen.end()) {
                int sz2 = dp[seen[sum - T]];
                if (sz2 != INT_MAX) {
                    ans = min(ans, sz2 + i - seen[sum - T]); 
                }
            }
            seen[sum] = i;
        }
        
        return ans == INT_MAX?-1:ans;
    }
};