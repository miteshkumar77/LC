// https://leetcode.com/problems/number-complement

class Solution {
public:
    int findComplement(int num) {
        list<int> nums; 
        while(num != 0) {
            nums.push_back(!(num % 2)); 
            num /= 2; 
        }
        for (int i : nums) {
            cout << i << ' ';
        }
        cout << endl; 
        int res = 0; 
        int count = 1; 
        for (int i : nums) {
            res += i * count; 
            count *= 2; 
        }
        
        return res; 
    }
};