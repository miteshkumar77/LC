// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr?curr->next:nullptr;
        bool dup = false;
        while(curr) {
            if (next && next->val == curr->val) {
                curr->next = next->next;
                next->next = nullptr;
                delete next;
                next = curr->next;
                dup = true;
            } else if (dup) {
                if (prev) {
                    prev->next = next;
                    curr->next = nullptr;
                    delete curr;
                    curr = next;
                    if (next)
                        next = next->next;
                    dup = false;
                } else {
                    curr->next = nullptr;
                    delete curr;
                    curr = next;
                    if (next)
                        next = next->next;
                    head = curr;
                    dup = false;
                }
            } else {
                prev = curr;
                curr = next;
                if (next)
                    next = next->next;
            }
        }
        return head;
    }
};