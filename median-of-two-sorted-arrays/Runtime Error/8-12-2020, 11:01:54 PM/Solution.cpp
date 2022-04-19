// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        
        function<int(int,int,int,int,int)> findKth = [&](int l1, int r1, int l2, int r2, int k) -> int {
            // cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << ' ' << k << endl; 
            if (l1 > r1) {
                return nums2[k]; 
            }
            if (l2 > r2) {
                return nums1[k]; 
            }
            
            if (k == 0) {
                return min(nums1[l1], nums2[l2]); 
            }
            
            
            int m1 = l1 + (r1 - l1)/2; 
            int m2 = l2 + (r2 - l2)/2; 
            
            if (m1 + m2 >= k) {
                if (nums1[m1] > nums2[m2]) {
                    return findKth(l1, m1 - 1, l2, r2, k); 
                } else {
                    return findKth(l1, r1, l2, m2 - 1, k); 
                }
            } else {
                if (nums1[m1] > nums1[m2]) {
                    return findKth(l1, r1, m2 + 1, r2, k - m2 - 1); 
                } else {
                    return findKth(m1 + 1, r1, l2, r2, k - m1 - 1); 
                }
            }
        };
        
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return findKth(0, nums1.size(), 0, nums2.size(), (nums1.size() + nums2.size())/2);
        } else {
            return (findKth(0, nums1.size(), 0, nums2.size(), (nums1.size() + nums2.size())/2) + findKth(0, nums1.size(), 0, nums2.size(), (nums1.size() + nums2.size())/2 + 1))/2; 
        }
    }
};