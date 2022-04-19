// https://leetcode.com/problems/rotate-list

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
    
    int getLen(ListNode* head) {
        int len = 0;
        while(head) {
            ++len;
            head = head -> next;
        }
        return len;
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        if (k == 0) {
            return head;
        }
        int len = getLen(head);
        k = (len - k % len) % len;
        if (k == 0) {
            return head;
        }
        ListNode* mid = head;
        ListNode* end = head;
        while(end -> next) {
            end = end -> next;
        }
        
        while(k - 1 > 0) {
            --k;
            mid = mid -> next;
        }
        end -> next = head;
        head = mid -> next;
        mid -> next = nullptr;
        
        return head;
        
        
    }
};