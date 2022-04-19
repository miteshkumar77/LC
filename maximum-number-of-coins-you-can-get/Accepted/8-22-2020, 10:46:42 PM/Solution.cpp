// https://leetcode.com/problems/maximum-number-of-coins-you-can-get

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end()); 
        
        int L = 0; 
        int R = piles.size() - 2; 
        int ans = 0; 
        while(L < R) {
            ans += piles[R]; 
            ++L; 
            R -= 2; 
        }
        return ans; 
    }
};