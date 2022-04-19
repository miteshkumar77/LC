// https://leetcode.com/problems/add-digits

class Solution {
public:
    int addDigits(int num) {
        int ans = 0; 
        ans += num%10;
        num/=10;
        ans += num%10;
        num/=10;
        ans += num%10;
        num/=10;
        ans += num%10;
        num/=10;
        ans += num%10;
        num/=10;
        ans += num%10;
        num/=10;
        ans += num%10;
        num/=10;
        ans += num%10;
        num/=10;
        ans += num%10;
        num/=10;
        ans += num%10;
        num/=10;
        num = ans; 
        ans = 0; 
        ans += num%10;
        num/=10;
        ans += num%10;
        num/=10;
        return ans; 
    }
};