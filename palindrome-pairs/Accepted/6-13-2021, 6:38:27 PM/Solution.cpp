// https://leetcode.com/problems/palindrome-pairs

class Solution {
public:
    
/*

    isPal(w1[] + w2[]) == ?
    
    case 1: 0 <= k <= w1.length
        any(isPal(w1[0:k] + w1[k:] + w2[])) ==
            any(isPal(w1[k:]) and reverse(w1[0:k]) == w2[])
    
    
    w1[0:x] + w1[x:] + w2[0:y] + w2[y:]
    isPal(w1[x:] + w2[0:y])
    
    case 2: 0 <= k <= w2.length
        any(isPal(w1[] + w2[0:k] + w2[k:])) ==
            any(isPal(w2[0:k]) && reverse(w1[]) == w2[k:])
    
    ex: w1[] = sl, w2[] = lls
    
    reverse(w1[]) == w2[1:] && isPal(w2[0:1]) => ls == ls && l is a palindrome


*/
    bool isPal(const string& wd) {
        int l = 0; int r = (int)wd.length() - 1;
        while(l < r) if (wd[l++] != wd[r--]) return false;
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, vector<int>> m1;
        unordered_map<string, vector<int>> m2;
        unordered_map<int, unordered_set<int>> pairs;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k <= words[i].length(); ++k) {
                auto w10k = words[i].substr(0, k); reverse(w10k.begin(), w10k.end());
                auto w1k = words[i].substr(k, words[i].length());
                if (isPal(w1k)) { 
                    m1[w10k].push_back(i);
                }
                if (w1k.length() == 0) m2[w10k].push_back(i);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            auto it = m1.find(words[i]);
            if (it != m1.end()) for (int j : it -> second) if (i != j) pairs[j].insert(i);
            for (int k = 0; k <= words[i].length(); ++k) {
                auto w20k = words[i].substr(0, k);
                auto w2k = words[i].substr(k, words[i].length());
                if (isPal(w20k)) {
                    it = m2.find(w2k);
                    if (it != m1.end()) for (int j : it -> second) if (i != j) pairs[j].insert(i);
                }
            }
        }
        vector<vector<int>> ans;
        for (const auto& p : pairs) {
            for (int j : p.second) ans.push_back({p.first, j});
        }
        return ans;
    }
};