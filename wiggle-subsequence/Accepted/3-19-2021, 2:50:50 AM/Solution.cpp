// https://leetcode.com/problems/wiggle-subsequence

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> p_greater_idx(n, -1);
        vector<int> p_lower_idx(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            while(!stk.empty() && nums[stk.top()] > nums[i]) {
                p_lower_idx[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        stk = stack<int>(); 
        for (int i = n - 1; i >= 0; --i) {
            while(!stk.empty() && nums[stk.top()] < nums[i]) {
                p_greater_idx[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        
        vector<int> is_higher(n, 1);
        vector<int> is_lower(n, 1);
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (p_greater_idx[i] != -1) {
                is_lower[i] = max(is_higher[p_greater_idx[i]] + 1, is_lower[p_greater_idx[i]]);
            }
            if (p_lower_idx[i] != -1) {
                is_higher[i] = max(is_lower[p_lower_idx[i]] + 1, is_higher[p_lower_idx[i]]); 
            }
            ans = max(ans, max(is_lower[i], is_higher[i]));
        }
        return ans;
        
    }
};