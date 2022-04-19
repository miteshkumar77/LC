// https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n

class Solution {
public:
    bool queryString(string S, int N) {
        unordered_set<int> st;
        int n = S.length();
        reverse(S.begin(), S.end());
        for (int i = 0; i < n; ++i) {
            int pow = 1;
            int num = 0;
            for (int j = 0; j < min(n - i, 30); ++j, pow <<= 1) {
                if (S[j+i] == '1') {
                    num |= pow;
                }
                if (num > 0 && num <= N) {
                    st.insert(num);
                }
            }
        }
        return st.size() == N;
    }
};