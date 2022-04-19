// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int L = 0; 
        int R = *max_element(arr.begin(), arr.end()); 
        int ans = L; 
        int chk_ans = chksum(arr, L); 
        
        while(L <= R) {
            int mid = L + (R - L)/2; 
            int chk_mid = chksum(arr, mid);
            if (abs(chk_mid - target) < abs(chk_ans - target)) {
                chk_ans = chk_mid; 
                ans = mid; 
            } else if (abs(chk_mid - target) == abs(chk_ans - target) && ans > mid) {
                ans = mid; 
                chk_ans = chk_mid; 
            }
            
            if (chk_mid >= target) {
                R = mid - 1; 
            } else {
                L = mid + 1; 
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