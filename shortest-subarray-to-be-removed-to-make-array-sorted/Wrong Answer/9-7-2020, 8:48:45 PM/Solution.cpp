// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted

class Solution {
public:
    
    bool check(vector<int>& arr, int len) {
        vector<bool> pre(arr.size(), false); 
        vector<bool> suf(arr.size(), false); 
        pre[0] = true; 
        suf.back() = true; 
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] < arr[i - 1]) {
                break;
            }
            pre[i] = true; 
        }
        for (int i = (signed int)arr.size() - 2; i >= 0; --i) {
            if (arr[i + 1] < arr[i]) {
                break;
            }
            suf[i] = true; 
        }
        if (pre[arr.size() - 1 - len] || suf[len]) {
            return true; 
        }
        int prev = INT_MIN; 
        for (int i = 0; i + len < arr.size(); ++i) {
            if (prev < arr[i + len] && (i == 0 || pre[i - 1]) && suf[i + len]) {
                return true; 
            }
            prev = arr[i]; 
        }
        return false; 
        
        
    }
    
    
    
    
   
 
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int L = 0; 
        int R = arr.size(); 
        int ans = R; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (check(arr, mid)) {
                ans = mid; 
                R = mid - 1; 
            } else {
                L = mid + 1; 
            }
        }
        return ans; 
    }
};