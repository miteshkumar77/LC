// https://leetcode.com/problems/sort-transformed-array

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (a == 0 && b == 0 && c == 0) {
            return nums; 
        }
        vector<int> ans(nums.size()); 
        int L = 0; 
        int R = nums.size() - 1; 
        if (a > 0) {
            for (int i = nums.size() - 1; i >= 0; --i) {
                if (func(nums[L], a, b, c) > func(nums[R], a, b, c)) {
                    ans[i] = func(nums[L++], a, b, c); 
                } else {
                    ans[i] = func(nums[R--], a, b, c); 
                }
            }
        } else if (a < 0) {
            for (int i = 0; i < nums.size(); ++i) {
                if (func(nums[L], a, b, c) < func(nums[R], a, b, c)) {
                    ans[i] = func(nums[L++], a, b, c); 
                } else {
                    ans[i] = func(nums[R--], a, b, c); 
                }
            }
        } else if (b >= 0) {
            for (int i = 0; i < nums.size(); ++i) {
                ans[i] = func(nums[i], a, b, c); 
            }
        } else if (b < 0) {
            for (int i = 0; i < nums.size(); ++i) {
                ans[nums.size() - 1 - i] = func(nums[i], a, b, c); 
            }
        }
        return ans; 
    }
    
    inline int func(int n, int a, int b, int c) {
        return a * n * n + b * n + c; 
    }
};