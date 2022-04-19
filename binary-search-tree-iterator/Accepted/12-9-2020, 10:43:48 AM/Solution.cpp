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
        this->cur = root;
    }
    
    int next() {
        while(cur) {
            stk.push(cur);
            cur = cur -> left;
        }
        TreeNode* ret = stk.top();
        cur = stk.top() -> right;
        stk.pop();
        return ret -> val;
    }
    
    bool hasNext() {
        return !stk.empty() || cur;
    }
private:
    stack<TreeNode*> stk;
    TreeNode* cur;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */