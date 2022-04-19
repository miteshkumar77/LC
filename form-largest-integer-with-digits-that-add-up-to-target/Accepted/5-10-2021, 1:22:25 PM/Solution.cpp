// https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> len(target + 1, 0);
        vector<int> d(target + 1, -1);
        int ip;
        d[0] = 0;
        for (int i = 1; i <= target; ++i) {
            for (int j = 9; j >= 1; --j) {
                ip = i - cost[j-1];
                if (ip >= 0 && d[ip] != -1 && len[ip]+1 > len[i]) {
                    len[i] = len[ip]+1;
                    d[i] = j;
                }
            }
        }
        if (d.back() == -1) return "0";
        string ans;
        int i = target;
        while(i > 0) {
            ans.push_back(d[i] + '0');
            i -= cost[d[i]-1];
        }
        return ans;
    }
};