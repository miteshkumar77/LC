// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        ListNode* next = nullptr;
        
        while(l1 || l2) {
            if (l1 && (!l2 || l1 -> val < l2 -> val)) {
                next = l1;
                l1 = l1 -> next;
            } else {
                next = l2;
                l2 = l2 -> next;
            }
            next -> next = nullptr;
            if (!head) {
                head = next;
            } else {
                curr -> next = next;
            }
            curr = next;

        }
        return head;
    }
};