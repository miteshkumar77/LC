// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    
    vector<TreeNode*> tr; 
    
    FindElements(TreeNode* root) {
         tr = vector<TreeNode*>();
        tr.reserve(1048576);
        tr.push_back(root);
        root -> val = 0; 
        int i = 0; 
        while (i < tr.size()) {
            if (tr[i] -> left) {
                tr[i] -> left -> val = (tr[i] -> val) * 2 + 1; 
                tr.push_back(tr[i] -> left); 
            }
            
            if (tr[i] -> right) {
                tr[i] -> right -> val = (tr[i] -> val) * 2 + 2; 
                tr.push_back(tr[i] -> right); 
            }
            ++i; 
        }
        
        for (TreeNode* x : tr) {
            cout << x -> val << ' '; 
        }
        cout << endl; 
    }
    
    
    bool find(int target) {
        int L = 0; 
        int R = tr.size() - 1; 
        int mid; 
        while(L <= R) {
            mid = L + (R - L)/2; 
            if (target > (tr[mid] -> val)) {
                L = mid + 1; 
            } else if (target < (tr[mid] -> val)) {
                R = mid - 1; 
            } else {
                return true; 
            }
        }
        
        return false; 
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */