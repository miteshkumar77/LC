// https://leetcode.com/problems/broken-calculator

class Solution {
public:
    int brokenCalc(int s, int t) {
        int a = 0;
        while(s < t) {
            t = (t % 2 == 0) ?  (t >> 1) : (t + 1);
            ++a;
        }
        cout << s << ' ' << t << endl;
        return a + (s - t);
    }
};