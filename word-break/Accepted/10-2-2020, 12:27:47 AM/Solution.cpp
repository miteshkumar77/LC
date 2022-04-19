// https://leetcode.com/problems/word-break

class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        TN* head = new TN();
        for (string& wd : wordDict) {
            insert(head, wd);
        }
        s = '#' + s;
        int n = s.length();
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            if (dp[i]) {
                TN* tmp = head;
                for (int j = i + 1; j < n; ++j) {
                    int idx = s[j] - 'a';
                    if (!(tmp -> letters)[idx]) {
                        break;
                    }
                    tmp = (tmp -> letters)[idx];
                    
                    dp[j] = dp[j] | tmp -> isEnd;
                }
            }
        }
        return dp.back();
    }
    
private:
    struct TN {
        TN () {
            fill(letters.begin(), letters.end(), nullptr);
            isEnd = false;
        }
        
        array<TN*, 26> letters;
        bool isEnd;
    };
    
    void insert(TN* head, string& wd) {
        for (char c : wd) {
            int idx = c - 'a';
            if (!(head -> letters)[idx]) {
                (head -> letters)[idx] = new TN();
            }
            head = (head -> letters)[idx];
        }
        head -> isEnd = true;
    }
};