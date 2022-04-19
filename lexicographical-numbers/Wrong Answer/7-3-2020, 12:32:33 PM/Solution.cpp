// https://leetcode.com/problems/lexicographical-numbers

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans; ans.reserve(n); 
        for (int i = 1; i < 10; ++i) {
            ans.push_back(i); 
            dfs(ans, i, 10, n); 
        }
        return ans; 
        
    }
    
    
   void dfs(vector<int>& ans, int root, unsigned long long int powr, int& cap) {
        
        for (int i = 0; i < 10; ++i) {
            if (root * powr + i <= cap) {
                ans.push_back(root * powr + i); 
                dfs(ans, ans.back(), powr * 10, cap); 
            }
        }
        return; 
    }
};