// https://leetcode.com/problems/merge-triplets-to-form-target-triplet

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> res(3, false);
        for (const auto& t : triplets) {
            vector<bool> cur(3, false);
            bool ok = true;
            for (int i = 0; i < 3; ++i) {
                if (t[i] > target[i]) {
                    ok = false;
                    break;
                } else if (t[i] == target[i]) {
                    cur[i] = true;
                }
            }
            if (ok) {
                for (int i = 0; i < 3; ++i) {
                    res[i] = res[i] || cur[i];
                }
            }
        }
        return res[0] && res[1] && res[2];
    }
};