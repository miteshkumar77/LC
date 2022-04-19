// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* rev(ListNode* cur, ListNode* prev) {
        if (!cur) return nullptr;
        auto n = cur->next;
        cur->next = prev;
        if (!n) return cur;
        return rev(n, cur);
    }
    ListNode* reverseList(ListNode* head) {
        return rev(head, nullptr);
    }
};