// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted

class Solution {
public:
    
    bool check(vector<int>& arr, int len) {
        int i = 0; 
        while(i + 1 < arr.size() && arr[i] <= arr[i + 1]) {
            ++i; 
        }
        if (i == 0) {
            if (!checks(arr, INT_MIN, i + len) && !checks(arr, arr[i], i + len + 1)) {
                return false; 
            }
        } else {
            if (!checks(arr, arr[i - 1], i + len) && !checks(arr, arr[i], i + len + 1)) {
                return false; 
            }
        }
        return true; 
    }
    
    bool checks(vector<int>& arr, int start, int i) {
        if (i < arr.size() && arr[i] < start) {
            return false; 
        }
        for (; i + 1 < arr.size(); ++i) {
            if (arr[i + 1] < arr[i]) {
                return false; 
            }
        }
        return true; 
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