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
        stack<TreeNode*> i1; 
        stack<TreeNode*> i2; 
        vector<int> ans; 
        
        function<TreeNode*()> getNextI1 = [&]() -> TreeNode* {
            if (i1.empty() && !root1) {
                return nullptr; 
            }
            
            while(root1) {
                i1.push(root1); 
                root1 = root1 -> left; 
            }
            
            TreeNode* tmp = i1.top(); 
            i1.pop(); 
            root1 = tmp -> right; 
            return tmp; 
        };
        
        function<TreeNode*()> getNextI2 = [&]() -> TreeNode* {
            if (i2.empty() && !root2) {
                return nullptr; 
            }
            
            while(root2) {
                i2.push(root2);
                root2 = root2 -> left;
            }
            
            TreeNode* tmp = i2.top(); i2.pop(); 
            root2 = tmp -> right; 
            return tmp; 
        };
        
        TreeNode* c1 = getNextI1(); 
        TreeNode* c2 = getNextI2(); 
        while(c1 || c2) {
            if (!c1) {
                ans.push_back(c2 -> val); 
                c2 = getNextI2(); 
            } else if (!c2) {
                ans.push_back(c1 -> val); 
                c1 = getNextI1(); 
            } else {
                if (c1 -> val <= c2 -> val) {
                    ans.push_back(c1 -> val); 
                    c1 = getNextI1(); 
                } else {
                    ans.push_back(c2 -> val); 
                    c2 = getNextI2(); 
                }
            }
        }
        return ans; 
        
        
    }
};