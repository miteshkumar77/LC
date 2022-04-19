// https://leetcode.com/problems/delete-columns-to-make-sorted-ii

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int wlen = A[0].length();
        int n = A.size();
        vector<bool> equals(n, true);
        int ans = 0;
        for (int i = 0; i < wlen; ++i) {
            char prev = A[0][i];
            bool isOk = true;
            for (int j = 1; j < n; ++j) {
                if (!equals[j]) continue;
                if (A[j][i] < prev) {
                    isOk = false;
                    ++ans;
                    break;
                }
                prev = A[j][i];
            }
            
            
            if (isOk) {
                prev = A[0][i];
                for (int j = 1; j < n; ++j) {
                    if (!equals[j]) continue;
                    if (A[j][i] > prev) {
                        equals[j] = false;
                    }
                    prev = A[j][i];
                }
            }
            
//             for (int i : equals) cout << i << ' ';
//             cout << endl;
            
//             cout << isOk << endl;
        }
        return ans;
    }
};