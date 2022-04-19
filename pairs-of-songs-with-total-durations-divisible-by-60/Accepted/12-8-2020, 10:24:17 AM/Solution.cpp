// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        array<int, 60> ct;
        fill(ct.begin(), ct.end(), 0);
        int ans = 0;
        for (int t : time) {
            int rem = (60 - t % 60) % 60;   
            ans += ct[rem];
            ++ct[t%60];

        }
        return ans;
    }
};