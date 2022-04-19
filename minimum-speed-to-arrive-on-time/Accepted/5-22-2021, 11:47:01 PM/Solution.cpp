// https://leetcode.com/problems/minimum-speed-to-arrive-on-time

class Solution {
public:
    bool possible(int speed, vector<int>& dist, double hour) {
        double total = 0;
        for (int i = 0; i < dist.size() - 1; ++i) {
            total += ceil((double)dist[i]/(double)speed);
        }
        total += (double)dist.back()/(double)speed;
        return total <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int r = 1e7;
        int ans = -1;
        int mid;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if (possible(mid, dist, hour)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            } 
        }
        return ans;
    }
};