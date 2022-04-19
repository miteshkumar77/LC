// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int L = 0; 
        int R = A.size(); 
        
        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (mid == 0) {
                if (A[mid] < A[mid + 1]) {
                    L = mid + 1; 
                } else {
                    return mid; 
                }
            } else if (mid == A.size()) {
                if (A[mid] < A[mid - 1]) {
                    R = mid - 1; 
                } else {
                    return mid; 
                }
            } else {
                if (A[mid] < A[mid - 1] && A[mid] > A[mid + 1]) {
                    R = mid - 1; 
                } else if (A[mid] > A[mid - 1] && A[mid] < A[mid + 1]) {
                    L = mid + 1; 
                } else {
                    return mid; 
                }
            }
        }
        return -1; 
        
        
    }
};