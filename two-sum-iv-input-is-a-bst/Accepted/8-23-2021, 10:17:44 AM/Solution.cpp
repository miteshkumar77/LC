// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur -> left;
            } else {
                cur = stk.top(); stk.pop();
                if (st.count(k - cur->val)) return true;
                st.insert(cur->val);
                cur = cur->right;
            }
        }
        return false;
    }
};










































