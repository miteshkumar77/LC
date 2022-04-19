// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string

class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.length(); 
        s += '_';
        int lvl = 0; 
        int ans = 0; 
        
        
        for (int i = 0; i < n; ++i) {
            
            if (s[i] == '(') {
                ++lvl; 
            }
            
            else if (s[i] == ')' && s[i + 1] == ')') {
                ++i; 
                --lvl; 
                if (lvl < 0) {
                    ++ans; 
                    lvl = 0; 
                }
                
            }
            
            else if (s[i] == ')' && s[i + 1] != ')') {
                if (lvl > 0) {
                    --lvl; 
                    ans++; 
                } else {
                    cout << i << ' ' << lvl << endl; 
                    ans += 2; 
                }
            }
        }
        ans += 2 * lvl; 
        return ans; 
    }
};