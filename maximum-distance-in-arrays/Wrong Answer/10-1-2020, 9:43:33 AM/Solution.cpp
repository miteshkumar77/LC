// https://leetcode.com/problems/maximum-distance-in-arrays

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        auto mx = [&](int a, int b) -> bool {
            return arrays[a][1] < arrays[b][1];    
        };
        
        auto mn = [&](int a, int b) -> bool {
            return arrays[a][0] > arrays[b][0];
        };
        
        
        priority_queue<int, vector<int>, decltype(mx)> max2(mx);
        priority_queue<int, vector<int>, decltype(mn)> min2(mn);
        
        for (int i = 0; i < arrays.size(); ++i) {
            max2.push(i); min2.push(i);
            if (max2.size() > 2) {
                max2.pop();
                min2.pop();
            }
        }
        
        vector<int> mins;
        vector<int> maxs;
        mins.push_back(arrays[min2.top()][0]); min2.pop(); mins.push_back(arrays[min2.top()][0]);
        maxs.push_back(arrays[max2.top()].back()); max2.pop(); maxs.push_back(arrays[max2.top()].back());
        
        return max(maxs[0] - mins[1], maxs[1] - mins[0]);
    }
};