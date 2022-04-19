// https://leetcode.com/problems/bag-of-tokens

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end()); 
        int n = tokens.size();
        int ans = 0;
        int s = 0;
        int l = 0;
        int r = n - 1;
        while(l <= r) {
            if (P >= tokens[l]) {
                
                // cout << "face up: " << tokens[l] << endl;
                P -= tokens[l++];
                ++s;
                ans = max(ans, s);
            } else if (s > 0) {
                // cout << "face dn: " << tokens[r] << endl;
                P += tokens[r--];
                --s;
            } else {
                break;
            }
        }
        return ans;
        
    }
};