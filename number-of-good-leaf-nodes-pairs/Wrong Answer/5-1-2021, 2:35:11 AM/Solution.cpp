// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs

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
    int d;
    int ans = 0;
    int countPairs(TreeNode* root, int distance) {
        d = distance;
        dfs(root, 0);
        return ans;
    }
    
    vector<int> dfs(TreeNode* root, int depth) {
        if (!root) {
            return vector<int>();
        }
        
        if (root -> left == nullptr && root -> right == nullptr) {
            return vector<int>{depth};
        }
        
        auto l = dfs(root -> left, depth + 1);
        auto r = dfs(root -> right, depth + 1);
        
        for (int i : l) {
            for (int j : r) {
                if (i + j <= d) {
                    ++ans;    
                }
            }
        }
        vector<int> ret;
        ret.reserve(l.size() + r.size());
        for (int i : l) ret.push_back(i);
        for (int i : r) ret.push_back(i);
        return ret;
    }
};