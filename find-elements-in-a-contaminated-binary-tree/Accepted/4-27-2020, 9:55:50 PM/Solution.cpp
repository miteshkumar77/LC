// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    
    unordered_set<int> tr; 
    FindElements(TreeNode* root) {
        root -> val = 0; 
        tr = unordered_set<int>(); 
        treeBuilder(root); 
        
    }
    
    void treeBuilder(TreeNode* root) {
        if (root -> left) {
            root -> left -> val = 2 * (root -> val) + 1; 
            tr.insert(root -> left -> val); 
            treeBuilder(root -> left); 
        }
        
        if (root -> right) {
            root -> right -> val = 2 * (root -> val) + 2; 
            tr.insert(root -> right -> val); 
            treeBuilder(root -> right); 
        }
    }
    
    bool find(int target) {
        return tr.find(target) != tr.end(); 
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */