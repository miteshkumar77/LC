// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        array<int, 60> m{};
        int ans = 0;
        for (int i : time) {
            ans += m[(60 - i % 60) % 60];
            ++m[i%60];
        }
        return ans;
    }
};