// https://leetcode.com/problems/special-binary-string

class Solution {
public:
    
    
    
    string ss(string& s, int L, int R) {
        return s.substr(L, R - L + 1); 
    }
    
    string makeLargestSpecial(string S) {
        string ans = S; 
        
        unordered_set<string> seen; 
        function<void(string)> bt = [&](string t) -> void {
            if (seen.find(t) != seen.end()) {
                return; 
            }
            
            if (t > ans) {
                ans = t; 
            }
            seen.insert(t); 
            
            unordered_map<int,vector<int>> vmap; 
            int cmp = 0; 
            
            for (int i = 0; i < t.length(); ++i) {
                if (t[i] == '1') {
                    ++cmp; 
                    vmap[cmp].push_back(i); 
                } else {
                    
                    if (vmap.find(cmp) != vmap.end()) {
                        for (int st : vmap[cmp]) {
                            
                            int cmp1 = 0; 
                            for (int x = st; x <= i; ++x) {
                                if (t[x] == '1') {
                                    ++cmp1; 
                                } else {
                                    --cmp1; 
                                    if (cmp1 == 0) {
                                        string post = ss(t, st, x); 
                                        string pre = ss(t, x + 1, i); 
                                        if (pre > post) {
                                            bt(ss(t, 0, st - 1) + pre + post + ss(t, i + 1, t.length() - 1)); 
                                        }
                                    }
                                }
                            }
                        }
                    }; 
                    
                    --cmp; 
                }
            }
        };
        
        bt(S); 
        return ans; 
    }
};