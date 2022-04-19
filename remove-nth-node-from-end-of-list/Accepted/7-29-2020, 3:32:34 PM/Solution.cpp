// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = nullptr; 
        ListNode* cur = head; 
        ListNode* plusk = head; 
        for (int i = 0; i < n; ++i) {
            plusk = plusk -> next; 
        }
        while(plusk) {
            pre = cur; 
            cur = cur -> next;
            plusk = plusk -> next; 
        }
        if (pre) {
            pre -> next = cur -> next; 
        }
        if (head == cur) {
            head = cur -> next; 
        }
        delete cur; 
        return head; 
        
    }
};