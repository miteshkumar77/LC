// https://leetcode.com/problems/bulb-switcher

class Solution {
public:
    int bulbSwitch(int n) {
        vector<int> bulbs(n, false); 
        int total = 0; 
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j < n; j += i) {
                if (bulbs[j]) {
                    bulbs[j] = false; 
                    --total;
                } else {
                    bulbs[j] = true; 
                    ++total; 
                }
            }
        }
        
        return total; 
    }
};