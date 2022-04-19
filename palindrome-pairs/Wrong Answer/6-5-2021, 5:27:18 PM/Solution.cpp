// https://leetcode.com/problems/palindrome-pairs

class Solution {
public:
    bool isPal(int i, int j, const string& wd) {
        while(i < j) if (wd[i++] != wd[j--]) return false; return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, vector<int>> dp;
        vector<vector<int>> ans;
        
        int i = 0;
        vector<int> empties;
        for (string& wd : words) {
            if (wd == "") {
                empties.push_back(i);
                continue;
            }           
            reverse(wd.begin(), wd.end());
            dp[wd].push_back(i);
            for (int x = (int)wd.length() - 1; x >= 0; --x) {
                if (isPal(x, (int)wd.length()-1, wd)) {
                    dp[wd.substr(0, x)].push_back(i);
                }
            }
            reverse(wd.begin(), wd.end());
            ++i;
        }
        i = 0;
        for (string& wd : words) {
            auto p = dp.find(wd);
            if (p != dp.end()) {
                for (int j : p->second) {
                    if (i == j) continue;
                    ans.push_back({i, j});
                }
            }
            ++i;
        }
        for (int e : dp[""]) {
            for (int v : empties) {
                if (e != v) ans.push_back({e, v});
            }
        }
        /*
        for (const auto& p : dp) {
            cout << p.first << ": ";
            for (int x : p.second) cout << x << ' ';
            cout << endl;
        }
        */
        return ans;
    }
};