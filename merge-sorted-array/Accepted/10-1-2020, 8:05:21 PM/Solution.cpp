// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
        int j = n - 1;
        int i = m - 1;
        int k = m + n - 1;
        while(i >= 0 || j >= 0) {
            if (i >= 0 && (j == -1 || (nums1[i] >= nums2[j]))) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        
    }
};