// https://leetcode.com/problems/delete-columns-to-make-sorted-ii

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int wlen = A[0].length();
        int n = A.size();
        vector<bool> equals(n, true);
        int ans = 0;
        for (int i = 0; i < wlen; ++i) {
            char prev = (char)0;
            bool isOk = true;
            for (int j = 0; j < n; ++j) {
                if (!equals[j]) continue;
                if (A[j][i] < prev) {
                    isOk = false;
                    ++ans;
                    break;
                }
                prev = A[j][i];
            }
            
            if (isOk) {
                prev = (char)0;
                for (int j = 0; j < n; ++j) {
                    if (!equals[j]) continue;
                    if (A[j][i] > prev) {
                        equals[j] = false;
                    }
                    prev = A[j][i];
                }
            }
        }
        return ans;
    }
};