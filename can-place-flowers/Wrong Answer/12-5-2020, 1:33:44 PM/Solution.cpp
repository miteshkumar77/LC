// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int m = flowerbed.size(); 
        int ans = 0;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if ((i == 0 || flowerbed[i - 1] == 0) && 
                (i == m - 1 || flowerbed[i + 1] == 0) &&
                 flowerbed[i] == 0) {
                flowerbed[i] = 1;
                ++ans;
            }
        }
        
        return ans;
    }
};