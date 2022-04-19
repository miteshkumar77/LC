// https://leetcode.com/problems/beautiful-arrangement-ii

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int l = 1;
        int r = k + 1;
        vector<int> ans; ans.reserve(n);
        
        while(l < r) {
            ans.push_back(l++);
            ans.push_back(r--);
        }
        
        if (l == r) {
            ans.push_back(l);
        }
        for (int i = k + 2; i <= n; ++i) {
            ans.push_back(i);
        }
        
        return ans;
        
            
    }
};