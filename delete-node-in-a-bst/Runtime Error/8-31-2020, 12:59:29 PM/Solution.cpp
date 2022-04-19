// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* target = find(root, key); 
        if (!target) {
            return root; 
        }
        if (isLeaf(root)) {
            delete root; 
            root = nullptr; 
            return root; 
        }
        
        TreeNode* bottom = getBottom(target); 
        int val; 
        bool done = false; 
        if (isLeaf(bottom -> left)) {
            
            val = bottom -> left -> val;
            if (bottom -> left == target) {
                done = true; 
            }
            delete bottom -> left; 
            bottom -> left = nullptr; 
        } else {
            val = bottom -> right -> val; 
            if (bottom -> right == target) {
                done = true; 
            }
            delete bottom -> right; 
            bottom -> right = nullptr; 
        }
        if (!done) {
            target -> val = val; 
            percolate(target); 
        }
        return root; 
        
    }
    
    void percolate(TreeNode* root) {
        if (!root) {
            return; 
        }
        if (root -> right && root -> val > root -> right -> val) {
            swap(root -> val, root -> right -> val); 
            percolate(root -> right); 
        } else if (root -> left && root -> val < root -> left -> val) {
            swap(root -> val, root -> left -> val); 
            percolate(root -> left); 
        }
    }
    
    bool isLeaf(TreeNode* root) {
        if (!root) {
            return false; 
        }
        return !root -> left && !root -> right; 
    }
    TreeNode* getBottom(TreeNode* root) {
        if (!root) {
            return nullptr; 
        }
        if (isLeaf(root)) {
            return root; 
        }
        if (isLeaf(root -> left) || isLeaf(root -> right)) {
            return root; 
        }
        
        if (root -> left) {
            return getBottom(root -> left);
        } else {
            return getBottom(root -> right); 
        }
    }
    
    TreeNode* find(TreeNode* root, int key) {
        while(root) {
            if (root -> val > key) {
                root = root -> left; 
            } else if (root -> val < key) {
                root = root -> right; 
            } else {
                return root; 
            }
        }
        return nullptr; 
    }
};