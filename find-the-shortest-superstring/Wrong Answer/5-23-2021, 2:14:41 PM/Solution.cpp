// https://leetcode.com/problems/find-the-shortest-superstring

class Solution {
public:
    vector<vector<string>> dp;
    vector<vector<int>> lcps;
    vector<string> words;
    unordered_set<int> two_powers;
    int n;
    string shortestSuperstring(vector<string>& words) {
        /*
            dp[i][j]: shortest superstring for subset with bitmask i if
            words[j] is the last string
        */
        /*
            lcps[i][j]: longest prefix of word j that is a suffix of word i
        */
        this->words = words;
        n = words.size();
        for (int i = 0; i <= n; ++i) {
            // cout << (1<<i) << endl;
            two_powers.insert(1<<i);
            
        }
        
        dp = vector<vector<string>> (1<<(n), vector<string>(n, ""));
        lcps = vector<vector<int>> (n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    lcps[i][j] = words[i].length();
                    continue;
                }
                for (int k = 0; k < min(words[j].length(), words[i].length()); ++k) {
                    if (words[j].substr(0, k + 1) == words[i].substr(words[i].length() - k - 1, k + 1)) {
                        lcps[i][j] = k + 1;
                    }
                }
            }
        }
        int len = INT_MAX;
        int ans = -1;   
        int pw = 0;
        for (int i = 0; i < n; ++i) {
            pw |= (1<<i);
        }
        for (int i = 0; i < n; ++i) {
            auto a = td(pw, i);
            // cout << words[i] << ' ' << a << endl;
            if (a.length() < len) {
                ans = i;
                len = a.length();
            }
        }
        return dp[pw][ans];
    }
    
    string td(int i, int j) {
        // cout << i << endl;
        if (two_powers.count(i)) {
            return words[j];
        }
        int pow = 1;
        int ni = i&(~(1<<j));
        int len = INT_MAX;
        for (int idx = 0; idx < n; ++idx, pow<<=1) {
            if (ni&pow) {
                auto a = td(ni, idx) + words[j].substr(lcps[idx][j], words[j].length());
                // cout << a << endl;
                if (a.length() < len) {
                    len = a.length();
                    dp[i][j] = a;
                }
            }
        }
        return dp[i][j];
    }
};








































