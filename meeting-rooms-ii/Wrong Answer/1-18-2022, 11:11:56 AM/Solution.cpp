// https://leetcode.com/problems/meeting-rooms-ii

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> const& a, vector<int> const& b) -> bool {
            return a[0] < b[0];   
        });
        
        priority_queue<int, vector<int>, less<int>> pq;
        int ans = 0;
        for (auto const& v : intervals) {
            while(!pq.empty() && pq.top() <= v[0])
                pq.pop();
            pq.push(v[1]);
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};