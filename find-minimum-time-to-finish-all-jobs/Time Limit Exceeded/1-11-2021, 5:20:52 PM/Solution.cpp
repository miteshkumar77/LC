// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> assigned(k, 0);
        vector<int> subset(k, 0);
        unordered_set<string> visited;
        int min_max = INT_MAX;
        function<string()> getConjoined = [&]() -> string {
            vector<int> cpy(subset.begin(), subset.end());
            sort(cpy.begin(), cpy.end());
            string ret;
            for (int i : cpy) {
                ret += to_string(i);
                ret += " ";
            }
            ret.pop_back();
            return ret;
        };
        
        
        function<void(int)> bt = [&](int job) -> void {
            
            if (job >= n) {
                min_max = min(min_max, *max_element(assigned.begin(), assigned.end()));
                return;
            }
            
            for (int worker = 0; worker < k; ++worker) {
                assigned[worker] += jobs[job];
                subset[worker] |= 1 << job;
                if (visited.find(getConjoined()) == visited.end() && assigned[worker] < min_max) {
                    visited.insert(getConjoined());
                    bt(job + 1);
                }
                assigned[worker] -= jobs[job];
                subset[worker] &= ~(1 << job);
            }
        };        
        
        bt(0);
        return min_max;
        
    }
};