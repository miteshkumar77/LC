// https://leetcode.com/problems/sort-list

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
    ListNode* sortList(ListNode* head) {
        
        if (!head) {
            return nullptr; 
        }
        
        
        array<ListNode*, 2> res = split(head); 
        if (!res[0] || !res[1]) {
            return merge(res[0], res[1]); 
        }
        
        
        ListNode* h1 = sortList(res[0]); 
        ListNode* h2 = sortList(res[1]); 
        
        return merge(h1, h2); 
        
        
//         while(res[0]) {
//             cout << res[0] -> val << ' ';
//             res[0] = res[0] -> next; 
//         }cout << endl; 
        
//         while(res[1]) {
//             cout << res[1] -> val << ' ';
//             res[1] = res[1] -> next; 
//         }
    }
    
    
    
    array<ListNode*, 2> split(ListNode* head) {
        if (!head) {
            return array<ListNode*, 2>{nullptr, nullptr}; 
        }
        ListNode* h1 = nullptr; 
        ListNode* h2 = nullptr; 
        ListNode* c1 = nullptr; 
        ListNode* c2 = nullptr; 
        
        while(head) {
            if (!h1) {
                h1 = head; 
            }
            
            if (c1) {
                c1 -> next = head; 
            }
            c1 = head; 
            
            head = head -> next; 
            if (!head) {
                break; 
            }
            if (!h2) {
                h2 = head; 
            }
            
            if (c2) {
                c2 -> next = head;  
            }
            c2 = head; 
            head = head -> next; 
        }
        
        c1 -> next = nullptr; 
        if (c2) {
            c2 -> next = nullptr; 
        }
        return array<ListNode*, 2>{h1, h2}; 
        
    }
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* head = nullptr; 
        ListNode* cur = nullptr; 
        
        while(h1 || h2) {
            ListNode* tmp = nullptr; 
            if (h1 && (!h2 || h1 -> val < h2 -> val)) {
                tmp = h1; 
                h1 = h1 -> next; 
            } else if (h2 && (!h1 || h2 -> val <= h1 -> val)) {
                tmp = h2; 
                h2 = h2 -> next; 
            }
            if (!head) {
                head = tmp; 
            }
            
            if (cur) {
                cur -> next = tmp; 
            }
            cur = tmp; 
        }
        return head; 
    }
};