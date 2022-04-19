// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m - 1;
        int i = n - 1;
        int k = m + n - 1;
        while(j >= 0 || i >= 0) {
            if (i < 0 || (j >= 0 && nums1[j] > nums2[i])) {
                nums1[k--] = nums1[j--];
            } else {
                nums1[k--] = nums2[i--];
            }
        }
    }
};