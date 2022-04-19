// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> alotted(k, 0);
        int sum = accumulate(jobs.begin(), jobs.end(), 0);
        int maxval = INT_MAX;
        
        int min_max = max(maxval, sum/2);
        sort(jobs.begin(), jobs.end());
        reverse(jobs.begin(), jobs.end());
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