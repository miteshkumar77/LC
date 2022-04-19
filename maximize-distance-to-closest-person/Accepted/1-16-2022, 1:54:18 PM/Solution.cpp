// https://leetcode.com/problems/maximize-distance-to-closest-person

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max_dist = 0;
        int dist = 0;
        int ans = 0;
        for (int i : seats) {
            if (i) {
                dist = 0;
            } else {
                ++dist;
                max_dist = max(max_dist, dist);
                if (max_dist % 2 == 1) {
                    ans = max(ans, (max_dist+1)/2);
                } else {
                    ans = max(ans, max_dist/2);
                }
            }
        }
        dist = 0;
        for (int i : seats) {
            if (i) break;
            ans = max(ans, ++dist);
        }
        
        for (int i : seats) {
            if (i) dist = 0;
            else ++dist;
        }
        ans = max(ans, dist);
        return ans;
    }
};