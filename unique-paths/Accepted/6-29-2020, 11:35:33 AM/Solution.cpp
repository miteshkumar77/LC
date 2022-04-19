// https://leetcode.com/problems/unique-paths

class Solution {
public:
    
    
    int choose(int n, int k) {
        if (k == 0) {
            return 1; 
        }
        return (unsigned long long int)n * choose(n - 1, k - 1)/k; 
    }
    int uniquePaths(int m, int n) {
        return choose(m + n - 2, n - 1); 
    }
};