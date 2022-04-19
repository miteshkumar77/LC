// https://leetcode.com/problems/super-washing-machines

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total = accumulate(machines.begin(), machines.end(), 0);
        if (total % n != 0) return -1;
        int perMachine = total / n;
        vector<int> pref(n+2, 0);
        vector<int> suff(n+2, 0);
        
        int j = n;
        for (int i = 1; i <= n; ++i, --j) {
            pref[i] += pref[i-1] + machines[i-1];
            suff[j] += suff[j+1] + machines[j-1];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int numMissingLeft = max(0, perMachine * (i-1) - pref[i-1]);
            int numMissingRight = max(0, perMachine * (n-i) - suff[i+1]);
            ans = max(ans, numMissingLeft + numMissingRight);
        }
        return ans;
    }
};

/*
  6 6 4 2 0
  0 2 4 6 6
    1 0 5
  0 1 1 6 6
  6 6 5 5 0
  
  
*/