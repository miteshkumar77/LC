// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(); 
        if (n == 0) {
            return nullptr; 
        }
        unordered_map<int, int> gt; 
        for (int i = 1; i <= n; ++i) {
            gt[inorder[i - 1]] = i;
        }
        
        
        
        function<int(TreeNode*, TreeNode*, int)> builder = 
            [&] (TreeNode* min, TreeNode* mid, int i) -> int {
            if (i <= -1) {
                return -1; 
            }
            int newVal = postorder[i]; 
            int retIdx; 
            if (gt[newVal] > gt[mid -> val]) {
                mid -> right = new TreeNode(newVal);
                retIdx = builder(mid, mid -> right, i - 1); 
            } else {
                if (!min || gt[newVal] > gt[min -> val]) {
                    mid -> left = new TreeNode(newVal);
                    retIdx = builder(min, mid -> left, i - 1);
                } else {
                    return i; 
                }
            }
            
            if (retIdx > -1) {
                int retVal = postorder[retIdx]; 

                if (!min || gt[retVal] > gt[min -> val]) {
                    mid -> left = new TreeNode(retVal);
                    return builder(min, mid -> left, retIdx - 1);
                } else {
                    return retIdx; 
                }
            } else {
                return -1; 
            }
            
            
        };
        
        
        
        TreeNode* root = new TreeNode(postorder[n - 1]);
        builder(nullptr, root, n - 2); 
        return root; 
    }
};