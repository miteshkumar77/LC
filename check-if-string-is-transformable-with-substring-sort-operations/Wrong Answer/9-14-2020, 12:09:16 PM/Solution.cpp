// https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations

class Solution {
public:
    bool isTransformable(string s, string t) {
        array<int, 10> cts; fill(cts.begin(), cts.end(), 0); 
        array<int, 10> ctt; fill(ctt.begin(), ctt.end(), 0); 
        for (char c : s) ++cts[c - '0']; 
        for (char c : t) ++ctt[c - '0']; 
        for (int i = 0; i < 10; ++i) {
            if (cts[i] != ctt[i]) {
                return false; 
            }
        }
        
        // cout << "anagrams" << endl; 
        
        array<deque<int>,10> lastpost; 
        for (int i = 0; i < t.length(); ++i) {
            lastpost[t[i] - '0'].push_back(i); 
        }
        
        array<int, 10> lastposs; fill(lastposs.begin(), lastposs.end(), INT_MIN); 
        vector<bool> done(s.length(), false); 
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i]; 
            lastposs[c - '0'] = i; 
            if (lastpost[c - '0'].front() <= i) {
                bool cheque = true; 
                for (int x = 0; x < (c - '0'); ++x) {
                    if (lastposs[x] >= lastpost[c - '0'].front()) {
                        cheque = false; 
                        break;
                    }
                }
                if (cheque) {
                    done[i] = true; 
                    lastposs[c - '0'] = lastpost[c - '0'].front(); 
                    lastpost[c - '0'].pop_front(); 
                    // cout << c << ' ';
                }
            }
        }
        
        fill(lastposs.begin(), lastposs.end(), INT_MAX); 
        for (int i = (signed int)s.length() - 1; i >= 0; --i) {
            char c = s[i]; 
            lastposs[c - '0'] = i; 
            if (!done[i]) {
                bool cheque = true; 
                // cout << s[i] << endl; 
                for (int x = 9; x > (c - '0'); --x) {
                    // cout << x << ' ' << lastposs[x] << ' ' << c << ' ' << lastpost[c - '0'].back() << endl; 
                    if (lastposs[x] <= lastpost[c - '0'].back()) {
                        cheque = false; 
                        break;
                    }
                }
                if (cheque) {
                    done[i] = true; 
                    lastposs[c - '0'] = lastpost[c - '0'].back(); 
                    lastpost[c - '0'].pop_back(); 
                } else {
                    return false; 
                }
            }
            
        }
        return true; 
    }
};