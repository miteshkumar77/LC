// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans; ans.reserve(n);
        
        for (; n > 0; --n) {
            for (int i = 1; i <= 26; ++i) {
                if ((k - i) <= 26 * (n - 1)) {
                    ans.push_back(i + 'a' - 1);
                    k -= i;
                    break;
                }
            }
        }
        return ans;
//         string ans; ans.reserve(k);
        
//         for (; k > 0; --k) {
//             for (int i = 1; i <= 26; ++i) {
//                 if ((n - i) <= 26 * (k - 1)) {
//                     ans.push_back(i + 'a');
//                     n -= i;
//                     break;
//                 }
//             }
//         }
//         return ans;
    }
};