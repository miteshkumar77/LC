// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int L = *min_element(arr.begin(), arr.end()); 
        int R = *max_element(arr.begin(), arr.end()); 
        int ans = L; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            int chk = chksum(arr, mid); 
            if (chk < target) {
                L = mid + 1; 
                ans = mid; 
            } else if (chk > target) {
                R = mid - 1; 
            } else {
                return mid; 
            }
        }
        return ans; 
    }
    
    
    int chksum(vector<int>& arr, int val) {
        int ans = 0; 
        for (int i : arr) {
            ans += min(val, i); 
        }
        return ans; 
    }
};