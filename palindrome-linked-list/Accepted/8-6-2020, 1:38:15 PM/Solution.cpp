// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true; 
        }
        ListNode* slow = head; 
        ListNode* pre = nullptr; 
        ListNode* fast = head; 
        while(fast) {
            pre = slow;
            slow = slow -> next; 
            fast = fast -> next; 
            fast = fast?fast -> next:nullptr; 
        }
        
        ListNode* h1 = head; 
        ListNode* h2 = slow;
        pre -> next = nullptr; 
        h2 = reverse(h2); 

        while(h1 || h2) {
            if (h1 && h2 && h1 -> val != h2 -> val) {
                return false; 
            }
            h1 = h1?h1->next:nullptr; 
            h2 = h2?h2->next:nullptr; 
        }
        return true; 
    }
    
    
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr; 
        ListNode* cur = head; 
        ListNode* nex = head?head->next:nullptr; 
        
        while(cur) {
            cur -> next = pre; 
            pre = cur; 
            cur = nex;
            if (nex) {
                nex = nex -> next; 
            }
        }
        return pre; 
    }
};