// https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        stk.push(root); 
        while(stk.top() -> left) {
            stk.push(stk.top() -> left); 
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int val = stk.top() -> val; 
        TreeNode* r = stk.top() -> right; 
        stk.pop(); 
        if (r) {
            stk.push(r); 
            while(stk.top() -> left) {
                stk.push(stk.top() -> left); 
            }
        }
        return val; 
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty(); 
    }
    
    
    stack<TreeNode*> stk; 
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */