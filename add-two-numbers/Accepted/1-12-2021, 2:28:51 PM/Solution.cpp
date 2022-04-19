// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        while(l1 || l2) {
            if (!l2) {
                if (curr) {
                    curr -> next = l1;
                } else {
                    head = l1;
                }
                curr = l1;
                l1 = l1 -> next;
            } else if (!l1) {
                if (curr) {
                    curr -> next = l2;
                } else {
                    head = l2;
                }
                curr = l2;
                l2 = l2 -> next;
            } else {
                if (curr) {
                    curr -> next = l1;
                } else {
                    head = l1;
                }
                curr = l1;
                l1 -> val += l2 -> val;
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
            curr -> val += carry;
            carry = curr -> val / 10;
            curr -> val %= 10;
            curr -> next = nullptr;
        }
        if (carry) {
            curr -> next = new ListNode(carry);
        }
        return head;
    }
};