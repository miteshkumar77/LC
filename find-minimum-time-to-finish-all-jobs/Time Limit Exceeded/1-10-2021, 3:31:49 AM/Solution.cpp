// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> alotted(k, 0);
        int min_max = INT_MAX;
        
        function<void(int)> bt = [&](int i) -> void {
            if (i == n) {
                min_max = min(min_max, *max_element(alotted.begin(), alotted.end()));
                return;
            }
            for (int x = 0; x < k; ++x) {
                if (alotted[x] + jobs[i] < min_max) {
                    alotted[x] += jobs[i];
                    bt(i + 1);
                    alotted[x] -= jobs[i];
                }
            }
        };
        bt(0);
        return min_max;
    }
};