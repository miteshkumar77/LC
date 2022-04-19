// https://leetcode.com/problems/time-needed-to-inform-all-employees

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        unordered_map<int, vector<int>> tree;
        for (int i = 0; i < manager.size(); ++i) {
            tree[manager[i]].push_back(i);
        }
        
        
        function<int(int)> calc = [&](int employee) -> int {
            if (tree.find(employee) == tree.end()) {
                return 0;
            }
            
            int maxtime = INT_MIN;
            
            for (int child : tree[employee]) {
                maxtime = max(maxtime, calc(child));
            }
            return maxtime +  informTime[employee];
        };
        
        return calc(headID);
    }
    
    
};