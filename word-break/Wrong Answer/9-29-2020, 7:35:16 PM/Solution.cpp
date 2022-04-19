// https://leetcode.com/problems/word-break

class Solution {
public:
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        s = '#' + s;
        int n = s.length();
        TN* head = new TN();
        for (string& wd : wordDict) {
            insert(head, wd);
        }
        
        
        vector<bool> dp(n, false);
        dp[0] = true;
        
        for (int i = 0; i < n; ++i) {
            if (dp[i]) {
                TN* tmp = head;
                for (int j = i + 1; j < n; ++j) {
                    char c = s[j];
                    
                    tmp = (tmp -> letters)[c - 'a'];
                    if (!tmp) {
                        break;
                    }
                    
                    dp[j] = tmp -> isEnd;
                }
            }
        }
        
        return dp.back();
    }
    
    
private:
    struct TN {
        TN() {
            fill(letters.begin(), letters.end(), nullptr);
            isEnd = false;
        }
        
        bool isEnd;
        array<TN*, 26> letters;
    };
    
    
    
    void insert(TN* head, string& word) {
        for (char c : word) {
            if (!(head -> letters)[c - 'a']) {
                (head -> letters)[c - 'a'] = new TN();
            } 
            
            head = (head -> letters)[c - 'a'];
        }
        head -> isEnd = true;
    }
    
};