class Solution {
public:
    using ll = long long;
    ll solve(string const& s, char x) {
        ll pref{0};
        ll suff{0};
        for (char c : s) {
            suff += (c == x);
        }
        int n = s.length();
        ll ans{0};
        for (char c : s) {
            suff -= (c == x);
            ans += pref * (c != x) * suff;
            pref += (c == x);
        }
        return ans;
    }
    
    long long numberOfWays(string s) {
        return solve(s, '0') + solve(s, '1');
    }
};