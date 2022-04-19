// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[0] > b[0];    
        });
        int n = p.size();
        int mt = p[0][0]; int mb = p[0][1];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (mt > p[i][0] && mb > p[i][1]) ++ans;
            mb = max(mb, p[i][1]);
        }
        return ans;
    }
};