// https://leetcode.com/problems/minimum-cost-to-connect-sticks

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int> > minq(sticks.begin(), sticks.end()); 
        int ans = 0; 
        while(minq.size() > 1) {
            int t1 = minq.top(); minq.pop(); 
            int t2 = minq.top(); minq.pop(); 
            ans += t1 + t2; 
            minq.push(t1 + t2); 
        }
        return ans; 
    }
};