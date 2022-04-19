// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        return (int)((sqrt(((unsigned long long int) n) * 8) - 1)/2); 
    }
};