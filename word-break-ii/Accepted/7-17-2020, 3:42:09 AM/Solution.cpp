// https://leetcode.com/problems/word-break-ii

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<list<int> > dp(s.length() + 1, list<int>()); 
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); 
        dp[0].push_back(0); 
        for (int i = 0; i <= s.length(); ++i) {
            if (dp[i].size() > 0) {
                string n = ""; 
                for (int j = i; j < s.length(); ++j) {
                    n += s[j]; 
                    if (dict.find(n) != dict.end()) {
                        dp[j + 1].push_back(i); 
                    }
                }
            }
        }
        
        if (dp.back().size() == 0) {
            return vector<string>(); 
        }
        vector<string> ans; 
        vector<list<pair<int, int> > > substrs; 
        list<pair<int, int> > box; 
        backtrack(dp, substrs, box, s.length());
        
        for (list<pair<int, int> > phrase: substrs) {
            string n = ""; 
            for (pair<int, int> word: phrase) {
                n += s.substr(word.first, word.second - word.first);
                n += ' '; 
            }
            n.pop_back(); 
            ans.push_back(n); 
        }
        return ans; 
        
    }
    
    void backtrack(vector<list<int> >& dp, vector<list<pair<int, int> > >& substrs, list<pair<int, int> >& box, int i) {
        if (i == 0) {
            substrs.push_back(list<pair<int, int> >(box.begin(), box.end())); 
            return; 
        }
        
        
        for (int l : dp[i]) {
            box.push_front(make_pair(l, i));
            backtrack(dp, substrs, box, l);
            box.pop_front(); 
        }
    }
};