// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    typedef array<int,2> pii; 
    int largestRectangleArea(vector<int>& heights) {
        vector<int> a1 = check(heights); 
        reverse(heights.begin(), heights.end()); 
        vector<int> a2 = check(heights);
        reverse(a1.begin(), a1.end()); 
        
        // for (int i : a1) cout << i << ' ';
        // cout << endl; 
        // for (int i : a2) cout << i << ' ';
        // cout << endl; 
        
        int ans = 0; 
        
        for (int i = 0; i < heights.size(); ++i) {
            ans = max(ans, a1[i] + a2[i] - heights[i]); 
        }
        return ans; 
    }
    
    
    vector<int> check(vector<int>& heights) {
        stack<pii> m;  
        vector<int> ans(heights.size()); 
        for (int i = 0; i < heights.size(); ++i) {
            pii cur{heights[i], 1}; 
            while(!m.empty() && m.top()[0] >= cur[0]) {
                cur[1] += m.top()[1]; 
                m.pop(); 
            }
            ans[i] = cur[1] * cur[0]; 
            m.push(cur); 
        }
        return ans; 
    }
};