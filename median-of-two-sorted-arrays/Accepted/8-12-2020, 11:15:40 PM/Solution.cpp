// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        
        
        
        function<int(int,int,int,int,int)> kth = [&](int l1, int r1, int l2, int r2, int k) -> int {
            if (l1 > r1) {
                return B[l2 + k]; 
            }
            
            if (l2 > r2) {
                return A[l1 + k]; 
            }
            
            int m1 = l1 + (r1 - l1)/2; int m2 = l2 + (r2 - l2)/2; 
            
            if ((m1 - l1) + (m2 - l2) < k) {
                if (A[m1] > B[m2]) {
                    return kth(l1, r1, m2 + 1, r2, k - (m2 - l2) - 1);
                } else {
                    return kth(m1 + 1, r1, l2, r2, k - (m1 - l1) - 1);
                }
            } else {
                if (A[m1] > B[m2]) {
                    return kth(l1, m1 - 1, l2, r2, k); 
                } else {
                    return kth(l1, r1, l2, m2 - 1, k); 
                }
            }
        };
        
        int li1 = 0; int ri1 = A.size() - 1; 
        int li2 = 0; int ri2 = B.size() - 1; 
        int len = A.size() + B.size(); 
        if (len % 2 == 1) {
            return kth(li1, ri1, li2, ri2, len/2); 
            
        } else {
            return ((double)(kth(li1, ri1, li2, ri2, len/2) + kth(li1, ri1, li2, ri2, (len/2) - 1)))/2; 
        }
    }
};