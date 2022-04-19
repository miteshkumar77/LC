// https://leetcode.com/problems/tuple-with-same-product

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int prod;
        int ans = 0;
        unordered_map<int,int> ct;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                prod = nums[i] * nums[j];
                if (ct.count(prod)) ans += 8 * ct[prod];
                ++ct[prod];
            }
        }
        return ans;
    }
};