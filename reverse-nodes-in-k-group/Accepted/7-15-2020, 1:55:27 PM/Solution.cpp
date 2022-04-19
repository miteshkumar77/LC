// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head; 
        }
        
        int i = 1; 
        ListNode* pre = nullptr; 
        ListNode* curr = head; 
        ListNode* next = head?head->next:head; 
        while(curr) {
            if (i == k) {
                i = 1; 
                if (!pre) {
                    curr -> next = nullptr; 
                    reverseSubList(head);
                    pre = head; 
                    pre -> next = next; 
                    head = curr; 
                    curr = next; 
                    next = curr?curr->next:nullptr; 
                    
                } else {
                    curr -> next = nullptr; 
                    reverseSubList(pre -> next); 
                    pre -> next -> next = next; 
                    ListNode* tmp = pre -> next; 
                    pre -> next = curr; 
                    pre = tmp; 
                    curr = next; 
                    next = curr?curr->next:nullptr; 
                }
            } else {
                ++i; 
                curr = next;
                next = next?next->next:nullptr; 
            }
        }
        return head; 
        
    }
    
    
    
    
    
    void reverseSubList(ListNode* start) {
        ListNode* pre = nullptr; 
        ListNode* mid = start; 
        ListNode* nex = mid?mid -> next:nullptr;
        while(mid) {
            mid -> next = pre; 
            pre = mid; 
            mid = nex; 
            nex = nex?nex->next:nullptr; 
        }
    }
};