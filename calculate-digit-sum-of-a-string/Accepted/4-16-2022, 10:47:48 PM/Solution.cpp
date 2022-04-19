// https://leetcode.com/problems/calculate-digit-sum-of-a-string

class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k) {
            int total{0};
            string tmp;
            for (int i = 0; i <= s.length(); ++i) {
                if (i < s.length()) {
                    total += (s[i]-'0');
                }
                if ((i+1) % k == 0 || (s.length() % k != 0 && i == s.length())) {
                    tmp += to_string(total);
                    // cout << total << ' ';
                    total = 0;
                }
                
            }
            // cout << endl;
            s = tmp;
        }
        return s;
    }
};