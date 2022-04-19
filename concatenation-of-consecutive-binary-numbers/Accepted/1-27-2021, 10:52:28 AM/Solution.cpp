// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers

class Solution {
public:
    typedef signed long long int slli;
    int concatenatedBinary(int n) {
        slli s = 0;
        slli M = 1e9 + 7; 
        for (slli i = 1; i <= n; ++i) {
            
            s = (s << ((slli)(log2(i)) + 1)) % M;
            // bitset<64> st(s);
            // cout << st << endl;
            s = (i + s) % M;
        }
        // bitset<64> st(s);
        // cout << st << endl;
        return s;
    }
};