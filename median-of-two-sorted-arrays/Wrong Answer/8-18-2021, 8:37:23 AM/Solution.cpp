// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    int kth(vector<int>& a, vector<int>& b, int la, int ra, int lb, int rb, int k) {
        int alen = ra - la + 1;    
        int blen = rb - lb + 1;
        
        if (alen == 0) {
            return b[lb];    
        }
        if (blen == 0) {
            return a[la];
        }
        if (k == 1) {
            return min(a[la], b[lb]);
        }
        
        int astep = min(k/2, alen);
        int bstep = min(k/2, blen);
        
        if (a[la + astep - 1] <= b[lb + bstep - 1]) {
            return kth(a, b, la + astep, ra, lb, rb, k-astep);
        }
        return kth(b, a, lb, rb, la, ra, k);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int alen = nums1.size(); int blen = nums2.size();
        int len = nums1.size() + nums2.size();
        double m1 = kth(nums1, nums2, 0, alen-1, 0, blen-1, len/2 + 1);
        
        // cout << len/2 << ' ' << len/2 + 1 << endl;
        if (len % 2 == 0) {
            double m2 = kth(nums1, nums2, 0, alen-1, 0, blen-1, len/2);
            // cout << m1 << ' ' << m2 << endl;
            return (m2 + m1)/2.0;
        }
        return m1;
    }
};