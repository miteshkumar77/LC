// https://leetcode.com/problems/special-binary-string

class Solution {
public:
    string makeLargestSpecial(string S) {
        
        while(true) {
            bool swapped = false; 
            int cmp = 0;
            unordered_map<int, vector<int>> mp; 
            for (int i = 0; i < S.length(); ++i) {
                if (S[i] == '1') {
                    ++cmp; 
                    mp[cmp].push_back(i); 
                } else {
                    --cmp; 
                    
                    if (mp.find(cmp + 1) != mp.end()) {
                        for (int start : mp[cmp + 1]) {
                            
                            int cmp2 = 0; 
                            
                            for (int j = start; j <= i; ++j) {
                                if (S[j] == '0') {
                                    --cmp2; 
                                } else {
                                    ++cmp2; 
                                }
                                
                                if (cmp2 == 0 && S.substr(start, j - start + 1) < S.substr(j + 1, i - j + 1)) {
                                    string s1 = S.substr(start, j - start + 1); 
                                    string s2 = S.substr(j + 1, i - j); 
                                    // cout << s1 << ' ' << s2 << endl; 
                                    S = S.substr(0, start) + s2 + s1 + S.substr(i + 1); 
                                    swapped = true; 
                                    break;
                                }
                            }
                            if (swapped) {
                                break;
                            }
                        }
                    }
                }
                if (swapped) {
                    break;
                }
            }
            
            if (!swapped) {
                break;
            }
        }
        
        return S; 
        
    }
};