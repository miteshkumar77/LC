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
        if (!head) {
            return nullptr; 
        }
        ListNode* cur = head; 
        ListNode* prev = nullptr; 
        while(cur) {
            if (cur -> next && cur -> next -> val == cur -> val) {
                int v = cur -> val; 
                while(cur && cur -> val == v) {
                    auto tmp = cur -> next; 
                    delete cur; 
                    cur = tmp; 
                }
                
                if (!prev) {
                    head = cur; 
                } else {
                    prev -> next = cur; 
                }
            } else {
                prev = cur; 
                cur = cur -> next; 
            }
        }
        return head; 
    }
};