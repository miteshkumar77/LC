// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i + n < nums1.size(); ++i) {
            nums1[i + n] = nums1[i];    
        }
        
        int i = n;
        int j = 0;
        for (int k = 0; k < m + n; ++k) {
            if (i != m + n && (j == n || nums1[i] < nums2[j])) {
                nums1[k] = nums1[i++];
            } else {
                nums1[k] = nums2[j++];
            }
        }
        
        
    }
};