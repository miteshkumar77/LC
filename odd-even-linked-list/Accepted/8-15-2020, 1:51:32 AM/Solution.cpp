// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        // odds
        ListNode* headptr = nullptr; 
        ListNode* curhead = nullptr;
        // evens
        ListNode* tailptr = nullptr;
        ListNode* curtail = nullptr; 
        
        int i = 0; 
        while(head) {
            if (i % 2 == 1) {
                if (curtail) {
                    curtail -> next = head; 
                } else {
                    tailptr = head; 
                }
                curtail = head; 
            } else {
                if (curhead) {
                    curhead -> next = head; 
                } else {
                    headptr = head; 
                }
                curhead = head; 
            }
            head = head -> next; 
            ++i; 
        }
        
        if (!headptr) {
            return tailptr; 
        }
        if (!tailptr) {
            return headptr; 
        }
        
        curtail -> next = nullptr; 
        curhead -> next = tailptr; 
        return headptr; 
        
    }
};