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
        unordered_map<int, int> hm;  
        for (int i = 0; i < n; ++i) {
            hm[inorder[i]] = i; 
        }
        
        
        
        function<TreeNode*(int, int, int, int)> builder = 
            [&] (int Lp, int Rp, int Li, int Ri) -> TreeNode* {
            
            if (Lp > Rp) {
                return nullptr; 
            }
            
            TreeNode* tmp = new TreeNode(postorder[Rp]);

            // cout << Lp << ' ' << Rp << ' ' << Li << ' ' << Ri << endl; 
            int rightsize = Ri - hm[postorder[Rp]];
            // cout << rightsize << endl; 
            tmp -> right = builder(Rp - rightsize, Rp - 1, hm[postorder[Rp]] + 1, Ri);
            tmp -> left = builder(Lp, Rp - rightsize - 1, Li, hm[postorder[Rp]] - 1);
            return tmp; 
        };
        
        return builder(0, n - 1, 0, n - 1);        
         
    }
};