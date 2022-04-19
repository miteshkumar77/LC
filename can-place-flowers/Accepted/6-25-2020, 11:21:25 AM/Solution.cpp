// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0; 
        bool plant = true; 
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (plant == true && flowerbed[i] == 1) {
                plant = false; 
            } else if (plant == false && flowerbed[i] == 1) {
                ans -= 1; 
            } else {
                if (plant) {
                    ++ans; 
                }
                plant = !plant; 
            }
            
            if (flowerbed[i] == 0 && plant && (i == flowerbed.size() - 1 || flowerbed[i + 1] != 1)) {
                if (ans >= n) {
                    return true; 
                }
            }
        }
        return ans >= n; 
         
    }
};