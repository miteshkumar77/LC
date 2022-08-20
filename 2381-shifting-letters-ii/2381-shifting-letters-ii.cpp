class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> delta(n+1, 0);
        for (auto const& v : shifts) {
            int sgn = (v[2] ? 1 : -1);
            delta[v[0]] += sgn;
            delta[v[0]] = (delta[v[0]] + 26) % 26;
            delta[v[1]+1] -= sgn;
            delta[v[1]+1] = (delta[v[1]+1] + 26) % 26;
        }
        int acc = 0;
        for (int i = 0; i < n; ++i) {
            acc += delta[i];
            s[i] = ((s[i] - 'a') + (acc % 26)) % 26 + 'a';
        }
        return s;
    }
};