// https://leetcode.com/problems/lexicographical-numbers

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans; ans.reserve(n); 
        for (int i = 1; i < 10; ++i) {
            if (i <= n) {
                ans.push_back(i); 
                dfs(ans, i, n); 
            } else {
                break; 
            }
        }
        return ans; 
        
    }
    
    
   void dfs(vector<int>& ans, int root, int& cap) {
        
        for (int i = 0; i < 10; ++i) {
            if (root * 10 + i <= cap) {
                ans.push_back(root * 10 + i); 
                dfs(ans, ans.back(), cap); 
            }
        }
        return; 
    }
};