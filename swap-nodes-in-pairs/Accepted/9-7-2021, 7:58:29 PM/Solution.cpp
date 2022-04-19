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
        ListNode* curr = head;
        ListNode* next = curr ? curr -> next : nullptr;
        if (!next) return curr;
        ListNode* root = nullptr;
        while(next) {
            ListNode* ncurr = next->next;
            ListNode* nnext = ncurr ? ncurr->next : nullptr;
            curr->next = nnext ? nnext : ncurr;   
            next->next = curr;
            if (!root) root = next;
            curr = ncurr;
            next = nnext;
        }
        return root;
    }
};