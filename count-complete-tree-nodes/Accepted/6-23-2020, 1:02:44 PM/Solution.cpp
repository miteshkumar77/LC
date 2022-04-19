// https://leetcode.com/problems/count-complete-tree-nodes

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
    int countNodes(TreeNode* root) {
        TreeNode* head = root; 
        int height = 0; 
        while(head) {
            ++height; 
            head = head -> left; 
        }
        int h = height; 
        
        unsigned long long int L = 0; 
        unsigned long long int R = pow(2, h - 1) - 1; 
        // cout << L << ' ' << R << endl; 
        unsigned long long int ans = L; 
        while(L <= R) {
            unsigned long long int mid = L + (R - L)/2; 
            if (!checkP(root, height, mid)) {
                ans = mid; 
                L = mid + 1; 
            } else {
                R = mid - 1; 
            }
        }
        
        unsigned long long int checkbit = pow(2, h - 2); 
        int result = 0; 
        for (int i = 0; i < h - 1; ++i) {
            if ((checkbit & ans) != 0) {
                ++result; 
            }
        }
        // cout << ans << endl; 
        
        
        unsigned long long int numToRight = pow(2, h - 1) - 1 - ans;
        // cout << numToRight << endl; 
        return pow(2, h) - 1 - numToRight; 
         
    }
    
    bool checkP(TreeNode* root, int h, unsigned long long int path) {
        unsigned long long int checkbit = pow(2, h - 2); 
        for (int i = 0; i < h - 1; ++i) {
            if ((checkbit & path) == 0) {
                root = root -> left; 
            } else {
                root = root -> right; 
            }
            
            if (!root) {
                return true; 
            }
            checkbit = checkbit >> 1; 
        }
        return false; 
    }
};