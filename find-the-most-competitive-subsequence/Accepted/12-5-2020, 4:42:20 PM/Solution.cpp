// https://leetcode.com/problems/find-the-most-competitive-subsequence

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        list<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            int left = nums.size() - i;
            while(!stk.size() == 0 && nums[i] < stk.back() && left > (k - stk.size())) {
                stk.pop_back(); 
            }
            if (stk.size() < k) {
                stk.push_back(nums[i]);
            }
        }
        
        return vector<int>(stk.begin(), stk.end()); 
    }
};