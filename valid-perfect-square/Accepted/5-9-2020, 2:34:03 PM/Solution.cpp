// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (unsigned long long int i = 0; i * i <= num; ++i) {
            if (i * i == num) {
                return true; 
            }
        }
        
        return false; 
    }
};