// https://leetcode.com/problems/squirrel-simulation

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int n = nuts.size(); 
        int max_sub = INT_MIN; 
        int total_dist = 0;
        int distance;
        for (int i = 0; i < n; ++i) {
            distance = abs(tree[0] - nuts[i][0]) + abs(tree[1] - nuts[i][1]); 
            total_dist += distance;
            max_sub = max(max_sub, distance - abs(squirrel[0] - nuts[i][0]) - abs(squirrel[1] - nuts[i][1])); 
        }
        return total_dist * 2 - max_sub;
                
        
        
        
    }
};