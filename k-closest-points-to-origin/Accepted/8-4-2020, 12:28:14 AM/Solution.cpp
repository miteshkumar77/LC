// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        auto compare = [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]; 
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxq(compare); 
        
        for (vector<int> a : points) {
            maxq.push(a); 
            if (maxq.size() > K) {
                maxq.pop(); 
            }
        }
        
        vector<vector<int>> ans; ans.reserve(K); 
        while(!maxq.empty()) {
            ans.push_back(maxq.top()); 
            maxq.pop(); 
        }
        return ans; 
    }
};