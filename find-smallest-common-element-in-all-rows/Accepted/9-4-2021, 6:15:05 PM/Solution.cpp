// https://leetcode.com/problems/find-smallest-common-element-in-all-rows

class Solution {
public:
    void proc_row(vector<int> const& r, map<int,int>& mp) {
        int prev = r.back() + 1;
        for (int i : r) {
            if (i != prev) ++mp[i];
            prev = i;
        }
    }
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int,int> mp;
        for (auto const& r : mat) {
            proc_row(r, mp);
        }
        int N = mat.size();
        for (auto const& p : mp) {
            if (p.second == N) return p.first;
        }
        return -1;
    }
};