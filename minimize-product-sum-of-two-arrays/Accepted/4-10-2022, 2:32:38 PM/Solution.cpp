// https://leetcode.com/problems/minimize-product-sum-of-two-arrays

class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        int prod{0};
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        reverse(nums2.begin(), nums2.end());
        for (int i = 0; i < nums1.size(); ++i) {
            prod += nums1[i] * nums2[i];
        }
        return prod;
    }
};