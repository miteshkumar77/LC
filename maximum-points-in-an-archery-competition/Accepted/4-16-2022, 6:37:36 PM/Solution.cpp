// https://leetcode.com/problems/maximum-points-in-an-archery-competition

class Solution {
public:
    /*
        x used in prev
        y used in total
        
    */
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        int high = INT_MIN;
        int best = -1;
        for (int i = 0; i < 1<<12; ++i) {
            int req{0};
            int score{0};
            for (int j = 0, p = 1; j < 12; ++j, p <<= 1) {
                if (p&i) {
                    req += (aliceArrows[j] + 1);
                    score += j;
                }
            }
            if (req <= numArrows && score > high) {
                high = score;
                best = i;
            }
        }
        
        vector<int> res(n);
        for (int i = 0, p = 1; i < n; ++i, p <<= 1) {
            if (p & best) {
                res[i] = aliceArrows[i] + 1;
                numArrows -= (aliceArrows[i] + 1);
            }
        }
        res[0] += numArrows;
        return res;
    }
};