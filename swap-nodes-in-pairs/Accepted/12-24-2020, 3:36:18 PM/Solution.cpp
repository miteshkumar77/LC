// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr?curr->next:nullptr;
        ListNode* tmp = nullptr;
        while(next) {
            tmp = next->next;
            next -> next = curr;
            curr -> next = tmp;
            if (prev) {
                prev -> next = next;
            } else {
                head = next;
            }
            
            prev = curr;
            curr = tmp;
            next = tmp?tmp->next:nullptr; 
        }
        return head;
    }
};