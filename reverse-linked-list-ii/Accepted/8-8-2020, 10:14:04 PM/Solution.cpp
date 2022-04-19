// https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* cur = head; 
        ListNode* pre = nullptr; 
        
        for (int i = 1; i < m; ++i) {
            pre = cur; 
            cur = cur -> next; 
        }
        
        ListNode* last = nullptr; 
        ListNode* new_head = nullptr; 
        for (int i = m; i <= n; ++i) {
            ListNode* tmp = cur -> next; 
            if (!new_head) {
                last = cur; 
            }
            cur -> next = new_head; 
            new_head = cur; 
            cur = tmp; 
        }
        
        if (pre) {
            pre -> next = new_head; 
        } else {
            head = new_head; 
        }
        last -> next = cur;
        
        return head; 
        
    }
};