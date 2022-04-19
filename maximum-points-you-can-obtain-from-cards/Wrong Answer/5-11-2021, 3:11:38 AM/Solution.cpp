// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        k = n - k;
        int s = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int ans = 0;
        int sz = 0;
        for (int i = 0; i < n; ++i) {
            s -= cardPoints[i];
            sz = min(sz+1, k);
            if (sz == k) {
                ans = max(ans, s);
                s += cardPoints[i-k+1];
            }
        }
        return ans;
    }
};