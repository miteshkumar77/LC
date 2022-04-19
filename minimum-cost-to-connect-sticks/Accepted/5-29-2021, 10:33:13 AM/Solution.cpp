// https://leetcode.com/problems/minimum-cost-to-connect-sticks

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        int a, b;
        while(pq.size() > 1) {
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        return ans;
    }
};