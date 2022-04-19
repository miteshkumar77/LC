// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int y = 0; 
        for (int i : nums) {
            y ^= i;
        }
        
        int lmo = y & (-y); 
        int x = 0;
        for (int i : nums) {
            if (lmo & i) {
                x ^= i; 
            }
        }
        
        return vector<int>{x, y ^ x};
    }
};