// https://leetcode.com/problems/word-break-ii

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int> > breaks(s.length() + 1, vector<int>());
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); 
        breaks[0].push_back(0); 
        for (int i = 0; i <= s.length(); ++i) {
            if (breaks[i].size() > 0) {
                string next = ""; 
                for (int j = i; j < s.length(); ++j) {
                    next += s[j]; 
                    if (dict.find(next) != dict.end()) {
                        breaks[j + 1].push_back(i);
                    }
                }
            }
        }
        
        vector<string> ans; 
        list<string> box; 
        backtrack(s, breaks, ans, box, s.length()); 
        return ans; 
        
        
    }
    
    void backtrack(string& input, vector<vector<int> >& breaks, vector<string>& ans, list<string>& box, int i) {
        if (i == 0) {
            string s = "";
            for (string v : box) {
                s += v; 
                s += ' ';
            }
            if (s.length() > 0) {
                s.pop_back();
            }
            ans.push_back(s);
            return;
        }
        
        
        for (int x : breaks[i]) {
            box.push_front(input.substr(x, i - x));
            backtrack(input, breaks, ans, box, x);
            box.pop_front(); 
        }
    }
    
    
};