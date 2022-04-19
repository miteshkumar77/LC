// https://leetcode.com/problems/best-sightseeing-pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        
        int n = A.size(); 
        int ans = INT_MIN;
        int maxseen = A[0];
        for (int i = 1; i < n; ++i) {
            ans = max(ans, A[i] + maxseen - 1);
            maxseen = max(maxseen - 1, A[i]); 
        }
        return ans;
    }
};