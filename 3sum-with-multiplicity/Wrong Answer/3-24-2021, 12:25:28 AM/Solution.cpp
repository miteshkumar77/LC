// https://leetcode.com/problems/3sum-with-multiplicity

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int> ct;
        int ans = 0;
        int mod = 1e9 + 7;
        int n = arr.size();
        int add;
        int sub;
        for (int i = 0; i < n; ++i) {
            
            for (const auto& p : ct) {
                sub = target - arr[i] - p.first;
                if (ct.count(sub)) {
                    if (sub == p.first) {
                        add = (p.second) * (p.second - 1) / 2;
                    } else {
                        add = (p.second) * ct[sub] / 2;
                    }
                    ans = (add + ans) % mod;
                }
            }
            ++ct[arr[i]];
        }
        return ans;
    }
};

        
        
