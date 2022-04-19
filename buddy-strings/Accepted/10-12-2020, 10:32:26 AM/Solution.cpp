// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        vector<int> diffs;
        vector<int> ct(26, 0);
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != B[i]) {
                diffs.push_back(i);
            } else {
                ++ct[A[i] - 'a'];
            }
            if (diffs.size() > 2) {
                return false;
            }
        }
        
        if (diffs.size() == 0) {
            for (int i : ct) {
                if (i >= 2) {
                    return true;
                }
            }
            return false;
        }
        
        if (diffs.size() != 2) {
            return false;
        }
        
        return B[diffs[0]] == A[diffs[1]] && B[diffs[1]] == A[diffs[0]];
    }
};