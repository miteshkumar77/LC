// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> stk;
        int n = nums.size() - 1;
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); ++i) {
            while(!stk.empty() && nums[i] > nums[stk.top()]) {
                ans[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        
        int j = 0;
        
        
        while(!stk.empty() && j < stk.top()) {
            if (nums[j] > nums[stk.top()]) {
                ans[stk.top()] = nums[j];
                stk.pop();
            } else {
                ++j;
            }
        }
        
        return ans;
    }
};