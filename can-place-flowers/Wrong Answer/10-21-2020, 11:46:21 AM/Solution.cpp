// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if (n == 0) {
            return true;
        }
        bool space = true;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 1) {
                space = false;
                continue;
            }
            
            if (space) {
                space = false;
                --n;
            } else {
                space = true;
            }
            if (n == 0) {
                return true;
            }
        }
        return false;
    }
};