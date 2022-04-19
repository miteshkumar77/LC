// https://leetcode.com/problems/max-number-of-k-sum-pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> ct;
        int n = nums.size();
        int ans = 0;
        for (int i : nums) {
            if (ct.count(k - i)) {
                ++ans;
                if (--ct[k-i] == 0) {
                    ct.erase(k - i);
                }
            } else {
                ++ct[i];
            }
        }
        return ans;
    }
};