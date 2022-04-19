// https://leetcode.com/problems/plus-one-linked-list

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
    ListNode* plusOne(ListNode* head) {
        int res = add(head);
        if (res != 0) {
            head = new ListNode(res, head);
        }
        return head;
    }
    
    int add(ListNode* head) {
        if (!head) {
            return 1;
        }
        int res = add(head -> next);
        int val = (head -> val + res) % 10;
        int ret = (head -> val + res) / 10;
        head -> val = val;
        return ret;
    }
};