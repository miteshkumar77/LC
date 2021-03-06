// https://leetcode.com/problems/concatenated-words

class Solution {
public:
    struct TN {
        
        TN() {
            letters = vector<TN*>(26, nullptr);
        }
        
        vector<TN*> letters;
        bool isEnd = false;
    };
    
    void insert(TN* head, string& wd) {
        for (char c : wd) {
            if (!(head -> letters)[c - 'a']) {
                (head -> letters)[c - 'a'] = new TN();
            }
            head = (head -> letters)[c - 'a'];
        }
        head -> isEnd = true;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        TN* head = new TN();
        for (string& wd : words) {
            insert(head, wd);
        }
        
        function<bool(string&)> isConcat = [&](string& wd) -> bool {
            
            string s = '#' + wd;
            vector<int> dp(wd.length() + 1, -1);
            dp[0] = 0;
            
            for (int i = 0; i < s.length(); ++i) {
                if (dp[i] == -1) continue;
                TN* cur = head;
                for (int j = i + 1; j < s.length(); ++j) {
                    cur = (cur -> letters)[s[j] - 'a'];
                    if (!cur) break;
                    if (cur -> isEnd) {
                        dp[j] = max(dp[j], dp[i] + 1);
                    }
                    
                    if (dp.back() > 1) {
                        return true;
                    }
                }
            }
            
            return dp.back() > 1;
            
        };
        vector<string> ans;
        for (string& s : words) {
            if (isConcat(s)) {
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};