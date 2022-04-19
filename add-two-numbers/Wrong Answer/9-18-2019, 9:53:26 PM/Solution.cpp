// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumList = new ListNode(0);
        ListNode* ret = sumList;
        
        while(l1 || l2) {
            if (l1) {
                sumList -> val += l1 -> val;
                l1 = l1 -> next;
            }
            
            if (l2) {
                sumList -> val += l2 -> val;
                l2 = l2 -> next;
            }
            if (!l1 && !l2) {
                break;
            }
            
            sumList -> next = new ListNode(sumList -> val / 10);
            sumList -> val %= 10;
            sumList = sumList -> next;
            
        }
        
        return ret;
    }
};