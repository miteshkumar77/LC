// https://leetcode.com/problems/building-boxes

class Solution {
public:
    
    bool check(int lvl, int total) {
        return total <= (lvl) * (lvl + 1) * (lvl + 2)/6; 
    }
    int minimumBoxes(int n) {
        int r = 1000; 
        int l = 1; 
        
        int ans;
        int mid;
        
        while(l <= r) {
            mid = l + (r - l)/2;
            if (check(mid, n)) {
                ans = (mid) * (mid + 1)/2;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
        
        
        
    }
};