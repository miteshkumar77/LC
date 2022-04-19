// https://leetcode.com/problems/bulls-and-cows

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> ct;
        for (char c : secret) ++ct[c]; 
        int A = 0; 
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++A; 
                --ct[secret[i]]; 
                guess[i] = '_'; 
                if (ct[secret[i]] == 0) {
                    ct.erase(secret[i]); 
                }
            }
        }
        int B = 0; 
        for (char c : guess) {
            if (ct.find(c) != ct.end()) {
                ++B; 
                --ct[c]; 
                if (ct[c] == 0) {
                    ct.erase(c); 
                }
            }
        }
        return to_string(A) + "A" + to_string(B) + "B"; 
    } 
};