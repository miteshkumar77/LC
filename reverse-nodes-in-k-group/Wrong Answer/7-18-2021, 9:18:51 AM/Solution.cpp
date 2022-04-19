// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* kth(ListNode* head, int k) {
        if (!head || !k) return head;
        return kth(head->next, k-1);
    }
    
    ListNode* reverse(ListNode* prev, ListNode* cur, ListNode* end) {
        ListNode* stop = end;
        ListNode* tmp;
        while(cur != end) {
            tmp = cur->next;
            cur->next = stop;
            stop = cur;
            cur = tmp;
        }    
        if (prev) prev->next = stop;
        return stop;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ret = nullptr;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* tmp;
        ListNode* hrt;
        while(cur) {
            tmp = kth(cur, k);
            hrt = reverse(pre, cur, tmp);
            if (!ret) ret = hrt;
            pre = cur;
            cur = tmp;
            
        }
        return ret;
    }
};