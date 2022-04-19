// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> stk;
        int i = 0;
        vector<int> ans(nums.size(), -1);
        while(stk.size() != nums.size() + 1) {
            while(!stk.empty() && nums[i] > nums[stk.top()]) {
                ans[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i++);
            i %= nums.size();
        }
        return ans;
    }
};