// https://leetcode.com/problems/serialize-and-deserialize-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
    
private:
    vector<int> split(string& s) {
        int prev = 0;
        vector<int> ans;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ',') {
                ans.push_back(stoi(s.substr(prev, i - prev)));
                prev = i + 1;
            }
        }
        return ans;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        return to_string(root -> val) + "," + serialize(root -> left) + serialize(root -> right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        vector<int> preorder = split(data);
        
        stack<TreeNode*> stk;
        TreeNode* root = new TreeNode(preorder[0]);
        stk.push(root);
        for (int i = 1; i < preorder.size(); ++i) {
            if (preorder[i] < stk.top() -> val) {
                stk.top() -> left = new TreeNode(preorder[i]);
                stk.push(stk.top() -> left);
            } else {
                TreeNode* tmp = nullptr;
                while(!stk.empty() && preorder[i] > stk.top() -> val) {
                    tmp = stk.top();
                    stk.pop();
                }
                tmp -> right = new TreeNode(preorder[i]);
                stk.push(tmp -> right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));