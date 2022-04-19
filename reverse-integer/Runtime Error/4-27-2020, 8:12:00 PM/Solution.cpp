// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int pow = 1; 
        int result = 0;
        list<int> digs = list<int>(); 
        while (x != 0) {
            digs.push_front(x % 10); 
            x /= 10; 
        }
        
        for (int num : digs) {
            result += pow * num; 
            pow *= 10; 
        }
        
        return result; 
    }
};