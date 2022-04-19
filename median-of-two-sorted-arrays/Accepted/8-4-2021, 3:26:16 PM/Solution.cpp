// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double kth(vector<int>& A, vector<int>& B, int al, int ar, int bl, int br, int k) {
        if (al > ar) {
            return B[bl + k-1];
        }
        if (bl > br) {
            return A[al + k-1];
        }
        if (k == 1) {
            return min(A[al], B[bl]);
        }
        int step = k/2;
        int amid = min(step, (ar - al+1));
        int bmid = min(step, (br - bl+1));
        
        if (A[al + amid-1] >= B[bl + bmid-1]) {
            return kth(A, B, al, ar, bl + bmid, br, k - bmid);
        }
        return kth(B, A, bl, br, al, ar, k);
    }
    
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int la = a.size();
        int lb = b.size();
        double m1 = kth(a, b, 0, la-1, 0, lb-1, (la + lb)/2+1);
        if ((la + lb) % 2 == 0) {
            return (m1 + kth(a, b, 0, la-1, 0, lb-1, (la + lb)/2))/2.0;
        }
        return m1;
    }
};