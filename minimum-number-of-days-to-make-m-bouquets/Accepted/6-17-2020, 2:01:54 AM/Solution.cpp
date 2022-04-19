// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        if (bloomDay.size() < m * k) {
            return -1; 
        }
        int L = *min_element(bloomDay.begin(), bloomDay.end()); 
        int R = *max_element(bloomDay.begin(), bloomDay.end()); 
        int ans = -1; 
        
        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (fuckunerd(bloomDay, mid, m, k)) {
                ans = mid; 
                R = mid - 1; 
            } else {
                L = mid + 1; 
            }
        }
        return ans; 
        
    }
    
    
    
    bool fuckunerd(vector<int>& bd, int t, int m, int k) {
        int num_bcts = 0; 
        int num_flwrs = 0; 
        for (int i = 0; i < bd.size(); ++i) {
            if (bd[i] <= t) {
                ++num_flwrs; 
                if (num_flwrs == k) {
                    num_flwrs = 0; 
                    ++num_bcts; 
                    if (num_bcts == m) {
                        return true; 
                    }
                }
            } else {
                num_flwrs = 0; 
            }
        }
        return false; 
    }
};