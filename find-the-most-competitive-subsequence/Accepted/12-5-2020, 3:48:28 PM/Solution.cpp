// https://leetcode.com/problems/find-the-most-competitive-subsequence

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            int left = nums.size() - i;
            // cout << i << ' ' << left << endl;
            while(!stk.size() == 0 && left > (k - stk.size()) && nums[i] < stk.back()) {
                stk.pop_back(); 
            }
            if (stk.size() < k) {
                stk.push_back(nums[i]);
            }
        }
        
        return stk; 
    }
};