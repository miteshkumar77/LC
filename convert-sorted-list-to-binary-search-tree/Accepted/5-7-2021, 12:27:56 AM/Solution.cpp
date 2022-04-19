// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

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
    TreeNode* f(int l, int r, const vector<ListNode*>& lns) {
        if (l > r) return nullptr;
        int mid = l + (r - l)/2;
        TreeNode* t = new TreeNode(lns[mid] -> val);
        t -> left = f(l, mid - 1, lns);
        t -> right = f(mid + 1, r, lns);
        return t;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*> lns; lns.reserve(10000);
        while(head) {
            lns.push_back(head);
            head = head->next;
        }
        int n = lns.size();
        return f(0, n - 1, lns);
    }
};