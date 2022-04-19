// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slowptr = head; 
        ListNode* fastptr = head; 
        if (head) {
            fastptr = head -> next; 
        }
        if (fastptr) {
            fastptr = fastptr -> next; 
        }
        while(fastptr) {
            if (slowptr == fastptr) {
                return true; 
            }
            slowptr = slowptr -> next; 
            fastptr = fastptr -> next; 
            if (fastptr) {
                fastptr = fastptr -> next; 
            }
        }
        return false; 
    }
};