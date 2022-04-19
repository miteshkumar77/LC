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
    
    typedef pair<ListNode*, ListNode*> pll;
    
    pll reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = head?head->next:nullptr;
        
        while(curr) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            next = next?next->next:nullptr;
        }
        
        return pll(prev, head);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = head;
        ListNode* curr = head;
        ListNode* preprev = nullptr;
        ListNode* rhead = nullptr;
        for (int i = 1; curr; ++i) {
            if (i % k == 0) {
                // cout << prev -> val << ' ' << curr -> val << endl;
                ListNode* next = curr -> next;
                curr -> next = nullptr;
                
                if (preprev) {
                    preprev -> next = nullptr;
                }
                pll headtail = reverse(prev);
                // cout << headtail.first->val << ' ' << headtail.second -> val << endl;
                if (preprev) {
                    preprev -> next = headtail.first;
                }
                if (!rhead) {
                    rhead = headtail.first;
                }
                headtail.second -> next = next;
                preprev = prev;
                prev = next;
                curr = next;
            } else {
                curr = curr -> next;
            }
            
        }
        return rhead;
    }
};