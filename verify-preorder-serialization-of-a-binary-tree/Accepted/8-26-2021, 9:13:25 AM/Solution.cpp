// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

class Solution {
public:
    bool isValidSerialization(string p) {
        int ct = 1;
        int n = p.length();
        for (int i = 0; i <= n; ++i) {
            if (i == n || p[i] == ',') {
                if (p[i-1] == '#') {
                    if (--ct < 0) return false;
                } else {
                    if (ct == 0) return false;
                    ++ct;
                }
            }
        }
        return ct == 0;
    }
};