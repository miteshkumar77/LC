// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;
        int mid;
        while(l < r) {
            mid = l + (r - l)/2;
            if (check(piles, mid, H)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        
        return ans;
        
    }
    
    bool check(const vector<int>& piles, int K, int H) {
        int total_time = 0;
        for (int i : piles) {
            total_time += ceil(((float)i)/K);
            if (total_time > H) {
                return false;
            }
        }
        return true;
    }
};