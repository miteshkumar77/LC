// https://leetcode.com/problems/maximum-distance-in-arrays

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        auto mx = [&](int a, int b) -> bool {
            return arrays[a].back() > arrays[b].back();    
        };
        
        auto mn = [&](int a, int b) -> bool {
            return arrays[a][0] < arrays[b][0];
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
        mins.push_back(min2.top()); min2.pop(); mins.push_back(min2.top());
        maxs.push_back(max2.top()); max2.pop(); maxs.push_back(max2.top());
        
        // for (int i : mins) cout << i << ' ';
        // cout << endl;
        // for (int i : maxs) cout << i << ' ';
        // cout << endl;
        int ans = INT_MIN;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (mins[i] != maxs[j]) {
                    ans = max(ans, arrays[maxs[j]].back() - arrays[mins[i]][0]);
                }
            }
        }
                
        return ans;

    }
};