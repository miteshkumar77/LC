// https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros

class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones = 0;
        int zeros = 0;
        int counter = 0;
        char prev = '_';
        for (char c : s) {
            if (c != prev) {
                if (prev == '1') {
                    ones = max(ones, counter);
                } else {
                    zeros = max(zeros, counter);
                }
                counter = 0;
            } 
                ++counter;
                prev = c;
            
        }
                if (prev == '1') {
                    ones = max(ones, counter);
                } else {
                    zeros = max(zeros, counter);
                }
        return ones > zeros; 
    }
};