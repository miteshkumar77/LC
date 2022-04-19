// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        array<int, 2> past {1, 2};
        if (n == 1 || n == 2) {
            return n; 
        }
        
        for (int i = 3; i <= n; ++i) {
            int tmp = past[0] + past[1]; 
            past[0] = past[1];
            past[1] = tmp;
        }
        return past[1]; 
    }
};