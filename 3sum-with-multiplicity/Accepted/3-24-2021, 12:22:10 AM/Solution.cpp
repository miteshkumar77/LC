// https://leetcode.com/problems/3sum-with-multiplicity

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int> ct;
        int ans = 0;
        int mod = 1e9 + 7;
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            ++ct[arr[i - 1]];
            for (int j = i + 1; j < n; ++j) {
                if (ct.count(target - arr[i] - arr[j])) {
                    ans = (ct[target - arr[i] - arr[j]] + ans) % mod;
                }
            }
        }
        return ans;
    }
};

