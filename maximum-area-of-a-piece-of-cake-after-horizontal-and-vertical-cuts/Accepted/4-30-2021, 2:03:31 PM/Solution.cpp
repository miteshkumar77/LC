// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(vc.begin(), vc.end());
        hc.push_back(h);
        sort(hc.begin(), hc.end());
        vc.push_back(w);
        int prev = 0;
        int mv = 0;
        for (int i : vc) {
            mv = max(mv, i - prev);
            prev = i;
        }
        
        int mh = 0;
        prev = 0;
        for (int i : hc) {
            mh = max(mh, i - prev);
            prev = i;
        }
        /*
        compute: mh * mv
        
        invariant: mhi * mvi
        
        */
        // cout << "mv: " << mv << " mh: " << mh << endl;
        int ans = 0;
        int M = 1e9 + 7;
        while(mh) {
            if (mh & 1)
                ans = (ans + mv) % M;
            mv = (2 * mv) % M;
            mh >>= 1;
        }
        return ans;
    }
};