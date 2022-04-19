// https://leetcode.com/problems/two-city-scheduling

typedef pair<int, vector<int>> piv; 
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<piv, vector<piv>, less<piv>> pq; 
        for (vector<int> p : costs) {
            pq.push(make_pair(p[1] - p[0], p)); 
        }
        int ans = 0; 
        for (int i = 0; i < costs.size()/2; ++i) {
            ans += pq.top().second[0]; 
            pq.pop(); 
        }
        for (int i = 0; i < costs.size()/2; ++i) {
            ans += pq.top().second[1]; 
            pq.pop(); 
        }
        return ans; 
    }
};