// https://leetcode.com/problems/path-sum-iii

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
    int pathSum(TreeNode* root, int sum) {
        
        unordered_map<int, int> prev_sums; 
        ++prev_sums[0]; 
        int ans = 0; 
        int rsum = 0; 
        function<void(TreeNode*)> helper = [&](TreeNode* r) -> void {
            if (!r) {
                return; 
            }
            
            rsum += r -> val; 
            if (prev_sums.find(rsum - sum) != prev_sums.end()) {
                ans += prev_sums[rsum - sum]; 
            }
            ++prev_sums[rsum]; 
            helper(r -> left); 
            helper(r -> right); 
            --prev_sums[rsum]; 
            rsum -= r -> val; 
            
            
        };
        
        
        helper(root); 
        return ans; 
        
    }
    
    
    
    
    
    
    
    
};