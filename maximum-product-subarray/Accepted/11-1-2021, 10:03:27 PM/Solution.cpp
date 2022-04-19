// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        signed long long ans = nums[0];
        signed long long pref_prod = 1;
        signed long long first_neg_prod = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            pref_prod *= nums[i];
            if (pref_prod == 0) {
                ans = max(ans, (signed long long) 0);
                first_neg_prod = 0;
                pref_prod = 1;
            } else {
                if (pref_prod < 0 && first_neg_prod == 0) {
                    first_neg_prod = pref_prod;
                } else if (pref_prod < 0) {
                    ans = max(ans, pref_prod/first_neg_prod);
                } else {
                    ans = max(ans, pref_prod);
                }
            }
        }
        return ans;
    }
};