// https://leetcode.com/problems/find-the-most-competitive-subsequence

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            while(!stk.size() == 0 && stk.back() > nums[i] && (k - stk.size() <= nums.size() - i - 1)) {
                stk.pop_back();
            }
            if (stk.size() < k) {
                stk.push_back(nums[i]);
            }
        }
        return stk;
    }
};