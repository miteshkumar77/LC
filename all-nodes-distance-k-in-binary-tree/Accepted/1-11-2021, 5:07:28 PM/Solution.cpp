// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    unordered_map<TreeNode*, int> distances;
    bool getTargetParents(TreeNode* root, TreeNode* target, int level, int& targetLevel, int K) {
        if (!root) return false;
        if (root == target) {
            targetLevel = level;
            distances[root] = 0;
            return true;
        }
        
        if (getTargetParents(root->left, target, level + 1, targetLevel, K)) {
            if (targetLevel - level < K) {
                if (root->right) {
                    distances[root->right] = (targetLevel - level) + 1;
                }
            } else {
                distances[root] = targetLevel - level;
            }
            return true;
        }
        
        if (getTargetParents(root->right, target, level + 1, targetLevel, K)) {
            if (targetLevel - level < K) {
                if (root->left) {
                    distances[root->left] = (targetLevel - level) + 1;
                }
            } else {
                distances[root] = targetLevel - level;
            }
            return true;
        }
        
        return false;
        
    }
    
    void getTargetChildren(TreeNode* root, int level, int K) {
        if (!root) return;
        if (level == K) {
            distances[root] = K;
            return;
        }
        getTargetChildren(root->left, level + 1, K);
        getTargetChildren(root->right, level + 1, K);
        
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (!root || !target) return vector<int>(); 
        
        int targetLevel = 0;
        getTargetParents(root, target, 0, targetLevel, K);
        getTargetChildren(target, 0, K); 
        unordered_map<TreeNode*, int> cpy(distances.begin(), distances.end());
        for (auto p : cpy) {
            if (p.second > 0) {
                getTargetChildren(p.first, p.second, K);
            }
        }
        vector<int> ans;
        for (auto p : distances) {
            if (p.second == K) {
                ans.push_back(p.first -> val);
            }
        }
        // for (auto p : distances) {
        //     cout << p.first -> val << ' ' << p.second << endl;
        // }
        return ans;
    }
};