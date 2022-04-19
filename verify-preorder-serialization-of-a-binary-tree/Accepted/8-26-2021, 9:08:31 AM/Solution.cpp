// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

class Solution {
public:
    bool isValidSerialization(string p) {
        stack<int> stk;
        stk.push(1);
        int n = p.length();
        for (int i = 0; i <= n; ++i) {
            if (!(i == n || p[i] == ',')) continue;
            while(!stk.empty() && stk.top() == 2) {
                stk.pop();
            }
            if (stk.empty()) return false;
            ++stk.top();
            if (p[i-1] != '#')
                stk.push(0);
            
        }
        while(!stk.empty() && stk.top() == 2) stk.pop();
        return stk.empty();
    }
};