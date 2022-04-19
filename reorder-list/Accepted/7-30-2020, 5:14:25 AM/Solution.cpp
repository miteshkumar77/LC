// https://leetcode.com/problems/reorder-list

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
    void reorderList(ListNode* head) {
        list<ListNode*> lbucket; 
        list<ListNode*> rbucket;
        ListNode* fast_ptr = head; 
        if (!head) {
            return;
        }
        // ListNode* fast_ptr = head -> next;
        // if (fast_ptr) {
        //     fast_ptr = fast_ptr -> next; 
        // }
        while(fast_ptr) {
            lbucket.push_back(head); 
            head = head -> next;
            fast_ptr = fast_ptr -> next;
            if (fast_ptr) {
                fast_ptr = fast_ptr -> next; 
            }
        }
        // head = head -> next; 
        while(head) {

            rbucket.push_front(head);
            head = head -> next; 
        }
        
        auto lit = lbucket.begin();
        auto rit = rbucket.begin(); 
        ListNode* cur = nullptr; 
        while(lit != lbucket.end() && rit != rbucket.end()) {
            if (cur) {
                cur -> next = (*lit);
            }
            cur = *lit;
            cur -> next = *rit;
            cur = cur -> next;
            ++lit;
            ++rit;
            
        }
        
        
        
        if (lit != lbucket.end()) {
            if (!cur) {
                return;
                
            }
            cur -> next = *lit;
            cur = cur -> next;
        }
        cur -> next = nullptr; 
        
        
        
    }
};