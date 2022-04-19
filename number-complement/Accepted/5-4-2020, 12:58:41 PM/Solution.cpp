// https://leetcode.com/problems/number-complement

class Solution {
public:
    int findComplement(int num) {
        list<int> nums; 
        while(num != 0) {
            nums.push_back(!(num % 2)); 
            num /= 2; 
        }
        int res = 0; 
        unsigned long long int count = 1; 
        for (int i : nums) {
            res += i * count; 
            count *= 2; 
        }
        
        return res; 
    }
};