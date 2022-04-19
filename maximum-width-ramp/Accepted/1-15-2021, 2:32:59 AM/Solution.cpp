// https://leetcode.com/problems/maximum-width-ramp

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        
        vector<int> descending;
        vector<int> nondescending;
        descending.push_back(0);
        for (int i = 1; i < n; ++i) {
            if (A[descending.back()] > A[i]) {
                descending.push_back(i);
            } else {
                nondescending.push_back(i);
            }
        }
        
       
        
        int j = descending.size();
        
        int ans = 0;
        
        for (int i = (int)nondescending.size() - 1; i >= 0; --i) {
            while(j > 0 && A[descending[j - 1]] <= A[nondescending[i]]) {
                --j;
            }
            if (j < descending.size() && A[descending[j]] <= A[nondescending[i]]) {
                ans = max(ans, max(nondescending[i] - descending[j], 0));
            }
        }
        return ans;
    }
};