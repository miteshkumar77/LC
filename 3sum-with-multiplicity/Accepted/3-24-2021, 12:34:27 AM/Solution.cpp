// https://leetcode.com/problems/3sum-with-multiplicity

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int> ct;
        int ans = 0;
        int mod = 1e9 + 7;
        int n = arr.size();
        int sub = 0;
        int add = 0;
        for (int i = 0; i < n; ++i) {
            
            for (const auto& p : ct) {
                sub = target - arr[i] - p.first;
                if (ct.count(sub)) {
                    if (sub == p.first) {
                        add = ((p.second) * (p.second - 1));
                    } else {
                        add = (p.second * ct[sub]);
                    }
                    
                    ans = (add + ans) % mod;
                }
                // cout << p.first << ": " << p.second << ", ";
            }
            // cout << endl;
            ++ct[arr[i]];
        }
        return ans/2;
    }
};
// 2 - 0 - 2 = 0
// 1 * 

        
        
