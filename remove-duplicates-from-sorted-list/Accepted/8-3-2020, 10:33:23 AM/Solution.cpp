// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head; 
        }
        ListNode* cur = head; 
        while(cur -> next) {
            if (cur -> val == cur -> next -> val) {
                ListNode* tmp = cur -> next -> next;
                cur -> next -> next = nullptr; 
                delete cur -> next; 
                cur -> next = tmp; 
                
            } else {
                cur = cur -> next; 
            }
        }
        return head; 
    }
};