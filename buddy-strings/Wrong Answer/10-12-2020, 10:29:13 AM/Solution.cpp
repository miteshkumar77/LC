// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        vector<int> diffs;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != B[i]) {
                diffs.push_back(i);
            }
            if (diffs.size() > 2) {
                return false;
            }
        }
        
        if (diffs.size() != 2) return false;
        
        return B[diffs[0]] == A[diffs[1]] && B[diffs[1]] == A[diffs[0]];
    }
};