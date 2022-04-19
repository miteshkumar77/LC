// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<bool> included(366, false); 
        for (int day : days) included[day] = true; 
        vector<int> mincost(366); 
        
        mincost[0] = 0; 
        for (int i = 1; i < mincost.size(); ++i) {
            mincost[i] = mincost[i - 1]; 
            if (included[i]) {
                mincost[i] += costs[0]; 
                mincost[i] = min(mincost[i], mincost[max(0, i - 7)] + costs[1]); 
                mincost[i] = min(mincost[i], mincost[max(0, i - 30)] + costs[2]); 
            }
        }
        return mincost.back(); 
        
        
    }
};