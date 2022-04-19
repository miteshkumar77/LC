// https://leetcode.com/problems/palindrome-pairs

class Solution {
public:
    bool isPal(const string& s, int l, int r) {
        while(l < r) if (s[l++] != s[r--]) return false;
        return true;
    }
    
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, vector<int>> m1;
        unordered_map<string, vector<int>> m2;
        unordered_map<int, unordered_set<int>> pairs; 
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k <= words[i].length(); ++k) {
                auto sl0k = words[i].substr(0, k); reverse(sl0k.begin(), sl0k.end());
                auto slk = words[i].substr(k, words[i].length() - k);
                if (isPal(slk, 0, (int)slk.length() - 1)) {
                    m1[sl0k].push_back(i);
                }
            }
            reverse(words[i].begin(), words[i].end());
            m2[words[i]].push_back(i);
            reverse(words[i].begin(), words[i].end());
        }
        
        for (int i = 0; i < n; ++i) {
            auto it = m1.find(words[i]);
            if (it != m1.end()) {
                for (int j : it -> second) if (i != j) pairs[j].insert(i);
            }
            for (int k = 0; k <= words[i].length(); ++k) {
                auto sr0k = words[i].substr(0, k);
                auto srk = words[i].substr(k, words[i].length() - k);
                if (isPal(sr0k, 0, (int)sr0k.length() - 1)) {
                    it = m2.find(srk);
                    if (it != m2.end()) {
                        for (int j : it -> second) if (i != j) pairs[j].insert(i);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (const auto& p : pairs) {
            for (int i : p.second) ans.push_back({p.first, i});
        }
        return ans;
    }
};