// https://leetcode.com/problems/all-elements-in-two-binary-search-trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
         
        vector<int> res; 
        stack<TreeNode*> s1; 
        stack<TreeNode*> s2; 
        res.reserve(10000); 
        
        while((!s1.empty() || root1) || (!s2.empty() || root2)) {
            if (root1) {
                s1.push(root1); 
                root1 = root1 -> left; 
            } else if (root2) {
                s2.push(root2); 
                root2 = root2 -> left; 
            } else {
                if ((!s1.empty()) && (s2.empty() || s1.top() -> val < s2.top() -> val)) {
                    res.push_back(s1.top() -> val); 
                    root1 = s1.top() -> right; 
                    s1.pop(); 
                    
                } else {
                    res.push_back(s2.top() -> val); 
                    root2 = s2.top() -> right; 
                    s2.pop(); 
                }
            }
        }
        
        return res; 
    }
    
    
};