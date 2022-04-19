// https://leetcode.com/problems/super-washing-machines

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total = accumulate(machines.begin(), machines.end(), 0); 
        if (total % n != 0) {
            return -1;
        }
        int final_ct = total/n;
        int suff = total;
        int pref = 0;
        vector<int> ops(n, 0); 
        
        for (int i = 0; i < n; ++i) {
            pref += machines[i];
            ops[i] = max(0, pref - (i + 1) * final_ct) + max(0, suff - (n - i) * final_ct); 
            suff -= machines[i];
        }
        
        return *max_element(ops.begin(), ops.end()); 
        
    }
};