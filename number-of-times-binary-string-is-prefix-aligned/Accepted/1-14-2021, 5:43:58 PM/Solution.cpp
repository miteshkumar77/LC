// https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int seenBulbs = 0;
        int highestSeen = 0;
        int ans = 0;
        for (int i = 0; i < light.size(); ++i) {
            ++seenBulbs;
            highestSeen = max(highestSeen, light[i]);
            if (seenBulbs == highestSeen) {
                ++ans;
            }
        }
        return ans;
    }
};