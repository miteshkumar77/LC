// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[0] > b[0];    
        });
        int n = p.size();
        int ans = 0;
        vector<int> max_b(n, p[0][1]);
        int j = 0;
        int mt = p[0][0];
        int mb = p[0][1];
        for (int i = 1; i < n; ++i) {
            while(j < i && p[j][0] > p[i][0]) {
                mt = p[j][0];
                mb = max_b[j];
                ++j;
            }
            // cout << mt << ' ' << mb << ' ' << p[i][0] << ' ' << p[i][1] << endl;
            ans += (p[i][0] < mt && p[i][1] < mb);
            max_b[i] = max(p[i][1], max_b[i-1]);
        }
        return ans;
    }
};
// [[1,1],[2,1],[2,2],[1,2]]
// [[2,1],[2,2],[1,1],[1,2]]
// [[2,1],[2,2],[1,2],[1,2]]