// https://leetcode.com/problems/meeting-rooms-ii

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        vector<pair<int,int>> ps;
        for (vector<int>& v : intervals) {
            ps.push_back(make_pair(v[0], 1));
            ps.push_back(make_pair(v[1], -1));
        }
        sort(ps.begin(), ps.end(), [](pair<int,int>& p1, pair<int,int>& p2) -> bool {
            return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
        });
        int gmax = 1;
        int curr = 0;
        for (auto p : ps) {
            cout << p.first << ' ' << p.second << endl;
            curr += p.second;
            gmax = max(gmax, curr);
        }
        return gmax;
    }
};