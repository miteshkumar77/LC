// https://leetcode.com/problems/maximum-product-of-word-lengths

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<string, int> seen;
        int i,j;
        int ans = 0;
        for (string& s : words) {
            sort(s.begin(), s.end());
            string f(s.begin(), unique(s.begin(), s.end()));
            for (const auto& p : seen) {
                i = 0; j = 0;
                bool good = true;
                while(i < f.length() && j < p.first.length()) {
                    if (f[i] > p.first[j]) {
                        ++j;
                    } else if (f[i] < p.first[j]) {
                        ++i;
                    } else {
                        good = false;
                        break;
                    }
                }
                if (good) ans = max(ans, (int)s.length() * p.second);
            }
            


            int v = s.length();
            if (seen.count(f)) {
                v = max(v, seen[f]);
            }
            seen[f] = v;
        }
        return ans;
    }
};