// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        for (int i = 0; (i + m) < arr.size(); ++i) {
            if (exists(arr, i, i + m - 1, k)) {
                return true; 
            }
        }
        return false; 
    }
    
    bool exists(vector<int>& arr, int L, int R, int k) {
        int ptr = L; 
        int ans = 0; 
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == arr[ptr]) {
                ++ptr; 
                if (ptr == (R + 1)) {
                    ++ans; 
                    ptr = L; 
                    if (ans == k) {
                        return true; 
                    }
                }
            } else {
                ans = 0; 
                ptr = L; 
            }
        }
        return false; 
    }
};