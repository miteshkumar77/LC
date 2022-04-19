// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> s;
        s[0] = -1;
        int n = nums.size();
        int acc = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            acc += (nums[i] ? 1 : -1);
            if (s.count(acc)) {
                ans = max(ans, i - s[acc]);
            } else {
                s[acc] = i;
            }
        }
        return ans;
    }
};