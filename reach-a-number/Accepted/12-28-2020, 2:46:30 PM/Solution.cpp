// https://leetcode.com/problems/reach-a-number

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int i;
        for (i = 0; sum < target; ++i, sum += i); 
        if ((sum - target) % 2 == 0) {
            return i;
        } else {
            return i + 1 + (i % 2 == 1);
        }
    }
};