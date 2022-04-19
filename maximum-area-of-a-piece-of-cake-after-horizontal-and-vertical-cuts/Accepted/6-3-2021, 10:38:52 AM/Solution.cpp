// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int prev = 0;
        int mhc = 0;
        int mvc = 0;
        for (int i : horizontalCuts) {
            mhc = max(mhc, i - prev);
            prev = i;
        }
        prev = 0;
        for (int i : verticalCuts) {
            mvc = max(mvc, i - prev);
            prev = i;   
        }
        int m = 1e9 + 7;
        return ((unsigned long long)mhc * (unsigned long long)mvc) % m;
    }
};