// https://leetcode.com/problems/split-array-into-fibonacci-sequence

class Solution {
public:
    
    inline bool check_val(int l, int r, string const& s) {
        auto tmp = s.substr(l, r - l + 1);
        if (tmp.length() == 1) return true;
        return tmp[0] != '0' && tmp.length() <= 10 && stoll(tmp) < (((ll)1)<<31);
    }
    
    using ll = long long;
    
    /*
    dp[i][j][k]: true iff prefix 0..i can be a fibonacci-like sequence ending with j and k
    */
    
    bool solve(string const& s, vector<unordered_map<ll, unordered_map<ll, bool>>>& dp, vector<int>& prev, int i, ll j, ll k) {
        if (i < 0) return true;
        if (dp[i].count(j) && dp[i][j].count(k)) return dp[i][j][k];
        for (int l = i; l >= max(0, i-10); --l) {
            if (check_val(l, i, s)) {
                auto tmp = s.substr(l, i-l+1);
                auto tmp_i = stoll(tmp);
                if ((((j == -1 || k == -1) && l > 0) || (tmp_i + j) == k) && solve(s, dp, prev, l-1, tmp_i, j)) {
                    prev[i] = l-1;
                    dp[i][j][k] = true;
                    return true;
                }
            }
        }
        dp[i][j][k] = false;
        return false;
    }
    
    
    
    
    vector<int> splitIntoFibonacci(string num) {
        int n = num.length();
        vector<unordered_map<ll, unordered_map<ll, bool>>> dp(n);
        vector<int> prev(n);
        if (!solve(num, dp, prev, n-1, -1, -1)) {
            return {};
        }
        int t = n-1;
        vector<int> ans;
        while(t > 0) {
            ans.push_back(stoi(num.substr(prev[t]+1, t - prev[t])));
            t = prev[t];
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};