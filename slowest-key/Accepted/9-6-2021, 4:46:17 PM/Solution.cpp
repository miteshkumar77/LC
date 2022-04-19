// https://leetcode.com/problems/slowest-key

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = keysPressed.length();
        char ans = keysPressed[0];
        int t = releaseTimes[0];
        for (int j = 1; j < n; ++j) {
            if (releaseTimes[j] - releaseTimes[j-1] > t || (releaseTimes[j] - releaseTimes[j-1] == t && keysPressed[j] > ans)) {
                t = releaseTimes[j] - releaseTimes[j-1]; ans = keysPressed[j];
            }
            }
        return ans;
    }
    
};