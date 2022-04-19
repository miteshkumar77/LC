// https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        vector<int> dp(target + 1, 0);
        vector<int> len(target + 1, 0);
        vector<int> d(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 9; j >= 1; --j) {
                int ip = i - cost[j-1];
                if (ip >= 0 && dp[ip] > 0 && len[ip] + 1 > len[i]) {
                    dp[i] = 2;
                    d[i] = j;
                    len[i] = len[ip]+1;
                }
            }
        }
        // for (int i : dp) cout << i << ' ';
        // cout << endl;
        if (dp.back() == 0) return "0";
        string ans;
        int i = target;
        while(i > 0) {
            
            if (dp[i] == 2) {
                // cout << i << endl;
                ans.push_back(d[i] + '0');
                i -= cost[d[i]-1];
            } else if (dp[i] == 1) {
                --i;
            } else {
                cout << i << ", " << dp[i] << ": " << "ERROR" << endl;
                return "0";
            }
        }
        return ans;
    }
};