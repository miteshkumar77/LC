// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int num) {
        int n = num; 
        vector<int> res(n + 1, 0); 
        int cap = 0; 
        int new_cap = cap; 
        while(true) {
            
            for (int i = 0; i <= cap; ++i) {
                if (i + 1 + cap > n) {
                    return res; 
                }
                ++new_cap; 
                res[i + 1 + cap] = res[i] + 1; 
            }
            cap = new_cap; 
        }
        
        return res; 
    }
};