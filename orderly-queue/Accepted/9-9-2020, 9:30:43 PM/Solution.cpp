// https://leetcode.com/problems/orderly-queue

class Solution {
public:
    string orderlyQueue(string S, int K) {
        string ans = S; 
        if (K == 1) {
            for (int i = 1; i < S.length(); ++i) {
                ans = min(ans, S.substr(i) + S.substr(0, i)); 
            }
            return ans; 
        }
        sort(ans.begin(), ans.end()); 
        return ans; 
        
    }
};