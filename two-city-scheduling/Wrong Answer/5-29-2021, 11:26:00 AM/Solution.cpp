// https://leetcode.com/problems/two-city-scheduling

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        auto it = costs.begin() + n;
        nth_element(costs.begin(), costs.end(), costs.begin() + n, [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[0] - a[1] < b[0] - b[1];
        });
        return accumulate(costs.begin(), it, 0, [](int sum, const vector<int>& a) -> int {
            return a[0] + sum;
        }) + 
        accumulate(it, costs.end(), 0, [](int sum, const vector<int>& a) -> int {
            return a[1] + sum;
        });
        
    }
};