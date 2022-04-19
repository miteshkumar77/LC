// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if (n == 0) return true;
        for (int i = 0; i < flowerbed.size(); ++i) {
            bool pre = i == 0 || flowerbed[i - 1] == 0;
            bool cur = flowerbed[i] == 0;
            bool nex = i == flowerbed.size() - 1 || flowerbed[i + 1] == 0;
            if (pre && cur && nex) {
                flowerbed[i] = 1;
                if (--n == 0) return true;
            }
        }
        return false;
    }
};