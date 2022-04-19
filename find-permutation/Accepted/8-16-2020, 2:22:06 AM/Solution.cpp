// https://leetcode.com/problems/find-permutation

class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ans(s.length() + 1); 
        stack<int> stk; 
        int j = 0; 
        for (int i = 1; i <= s.length(); ++i) {
            if (s[i - 1] == 'I') {
                stk.push(i); 
                while(!stk.empty()) {
                    ans[j++] = stk.top(); stk.pop(); 
                }
            } else {
                stk.push(i); 
            }
        }
        stk.push(s.length() + 1); 
        while(!stk.empty()) {
            ans[j++] = stk.top(); stk.pop(); 
        }
        return ans; 
    }
};