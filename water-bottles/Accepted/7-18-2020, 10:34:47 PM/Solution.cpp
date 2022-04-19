// https://leetcode.com/problems/water-bottles

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = 0;
        int ans = 0; 
        while(numBottles > 0 || emptyBottles >= numExchange) {
            if (numBottles > 0) {
                ans += numBottles;
                emptyBottles += numBottles;
                numBottles = 0; 
            } else {
                numBottles = emptyBottles/numExchange;
                emptyBottles %= numExchange;
            }
        }
        return ans; 
    }
};