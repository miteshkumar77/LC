class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<array<int, 2>> count;
        for (auto const& v : intervals) {
            count.push_back({v[0], 0});
            count.push_back({v[1], 1});
        }
        sort(count.begin(), count.end());
        int ans{0};
        int overlaps{0};
        for (auto const& a : count) {
            if (a[1] == 0) {
                ++overlaps;
                ans = max(ans, overlaps);
            } else {
                --overlaps;
            }
        }
        return ans;
    }
};