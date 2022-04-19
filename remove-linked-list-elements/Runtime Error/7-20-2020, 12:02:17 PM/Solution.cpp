// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head -> val == val) {
            ListNode* tmp = head -> next; 
            delete head; 
            head = head -> next; 
        }
        
        ListNode* curr = head; 
        while(curr && curr -> next) {
            ListNode* tmp = curr -> next; 
            if (tmp -> val == val) {
                curr -> next = tmp -> next;
                delete tmp; 
            } else {
                curr = curr -> next; 
            }
            
        }
        
        return head; 
    }
};