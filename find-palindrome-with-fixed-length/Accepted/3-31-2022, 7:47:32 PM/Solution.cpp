// https://leetcode.com/problems/find-palindrome-with-fixed-length

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int n = queries.size();
        vector<string> v(n, string(intLength, '0'));
        int p = (intLength + 1)/2;
        cout << p << endl;
        vector<long long> fact(p+1, 1);
        for (int i = 1; i <= p; ++i) {
            fact[i] = fact[i-1] * (i == p ? 9 : 10);
        }
        
        for (int i = 0; i < n; ++i) {
            if (queries[i] > fact[p]) {
                v[i] = to_string(-1);
                continue;
            }
            for (int j = 0; j < p; ++j) {
                int f = (j == 0 ? 1 : 0);
                int l = 9;
                for (int k = f; k <= l; ++k) {
                    int lo = 1 + (k - f) * fact[(p - j - 1)];
                    int hi = (k + 1 - f) * fact[(p - j - 1)];
                    if (lo <= queries[i] && hi >= queries[i]) {
                        queries[i] -= (lo-1);
                        v[i][j] = k + '0';
                        break;
                    }
                }
            }
            int x = intLength % 2 == 0 ? p-1 : p-2;
            for (int j = p; j < intLength; ++j, --x) {
                v[i][j] = v[i][x];
            }
        }
        vector<long long> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = stoll(v[i]);
        return ans;
    }
};