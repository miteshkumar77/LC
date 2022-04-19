// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> ct;
        int ans = 0;
        for (int t : time) {
            int rem = (60 - t % 60) % 60;
            if (ct.find(rem) != ct.end()) ans+=ct[rem];
            
            ++ct[t%60];

        }
        return ans;
    }
};