// https://leetcode.com/problems/longest-mountain-in-array

class Solution {
public:
    int longestMountain(vector<int>& A) {
        
        int lans = 0;
        int gans = 0;
        
        int state = 0; // 0 -> nothing, 1 -> increased already, 2 -> increased and decreased already
        
        for (int i = 1; i < A.size(); ++i) {
            // cout << i << ' ' << state << endl;
            if (A[i] > A[i - 1]) {
                if (state != 1) {
                    lans = 1; 
                    state = 1;
                }
                ++lans;
            } else if (A[i] < A[i - 1]) {
                if (state == 1) {
                    state = 2; 
                }
                if (state == 2) {
                    ++lans; 
                    gans = max(gans, lans);
                } else {
                    lans = 0; 
                }
            } else {
                lans = 0;
                state = 0;
            }
        }
        return gans;
        
    }
};