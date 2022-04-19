// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv

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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_map<TreeNode*, TreeNode*> parents;
        unordered_map<TreeNode*, int> depth;
        function<void(TreeNode*,TreeNode*,int)> setParents = [&](TreeNode* cur, TreeNode* parent, int d) -> void {
            if (!cur) return;
            parents[cur] = parent;
            depth[cur] = d;
            setParents(cur -> left, cur, d+1); 
            setParents(cur -> right, cur, d+1);
        };
        
        setParents(root, nullptr, 0);
        
        int mindepth = INT_MAX;
        for (auto t : nodes) {
            mindepth = min(mindepth, depth[t]);
        }
        
        for (int i = 0; i < nodes.size(); ++i) {
            while(depth[nodes[i]] > mindepth) {
                nodes[i] = parents[nodes[i]];
            }
        }
        
        unordered_set<TreeNode*> level(nodes.begin(), nodes.end()); 
        
        while(level.size() > 1) {
            unordered_set<TreeNode*> next_level; 
            for (TreeNode* t : level) {
                next_level.insert(parents[t]); 
            }
            level.swap(next_level);
        }
        
        return *level.begin();
    }
};