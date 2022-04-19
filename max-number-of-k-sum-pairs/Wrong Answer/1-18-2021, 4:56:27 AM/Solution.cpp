// https://leetcode.com/problems/max-number-of-k-sum-pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> ct;
        int ans = 0;
        for (int i : nums) {
            if (ct.count(k - i)) {
                ans += 1;
            }
            ++ct[i];
        }
        return ans;
    }
};