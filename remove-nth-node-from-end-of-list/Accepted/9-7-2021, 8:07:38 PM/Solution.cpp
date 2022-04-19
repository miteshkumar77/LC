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
        ListNode* cur = head;
        while(n--) {
            cur = cur->next;
        }
        ListNode* prev = nullptr;
        ListNode* rem = head;
        while(cur) {
            cur = cur->next;
            prev = rem;
            rem = rem->next;
        }
        if (prev) {
            prev->next = rem->next;
            rem->next = nullptr;
            delete rem;
            return head;
        } else {
            prev = rem->next;
            rem->next = nullptr;
            delete rem;
            return prev;
        }
    }
};