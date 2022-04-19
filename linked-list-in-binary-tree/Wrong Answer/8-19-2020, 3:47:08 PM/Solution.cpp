// https://leetcode.com/problems/linked-list-in-binary-tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        return helper(head, head, root); 
    }
    
    bool helper(ListNode* head, ListNode* cur, TreeNode* root) {
        if (!cur) {
            return true; 
        }
        
        if (!root) {
            return false; 
        }
        ListNode* nxt; 
        if (root -> val == cur -> val) {
            nxt = cur -> next; 
        } else {
            nxt = head; 
        }
        
        return helper(head, nxt, root -> left) || helper(head, nxt, root -> right); 
    }
};