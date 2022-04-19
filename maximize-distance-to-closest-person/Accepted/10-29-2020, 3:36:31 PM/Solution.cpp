// https://leetcode.com/problems/maximize-distance-to-closest-person

class Solution {
public:
    typedef unsigned long long int ulli;
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<ulli> pref(n);
        vector<ulli> suff(n);
        ulli pre = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (seats[i]) {
                pref[i] = 0;
            } else {
                pref[i] = pre + 1;
            }
            pre = pref[i];
        }
        
        for (int i = n - 1; i >= 0; --i) {
            if (seats[i]) {
                suff[i] = 0;
            } else {
                suff[i] = pre + 1;
            }
            pre = suff[i];
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ans = max((ulli)ans, min(suff[i], pref[i]));
        }
        return ans;
    }
};