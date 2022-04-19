// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> stk;
        int n = nums.size() - 1;
        vector<int> ans(nums.size(), INT_MIN);
        for (int i = 0; i < nums.size(); ++i) {
            while(!stk.empty() && nums[i] > nums[stk.top()]) {
                ans[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        
        int j = 0;
        stk = stack<int>();
        
        for (int i = n; i >= 0; --i) {
            
            if (ans[i] == INT_MIN) {
                // cout << ans[i] << ' ' << nums[i] << ' ' << ans[j] << ' ' << i << endl;
                while(j < i && ans[j] <= nums[i]) {
                    ++j;
                }
                if (j < i) {
                    // cout << i << ' ' << ans[i] << ' ' << nums[j] << endl;
                    ans[i] = ans[j];
                }
            }
        }
        for (int& i : ans) {
            i = i == INT_MIN?-1:i;
        }
        return ans;
    }
};