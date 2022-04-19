// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = l1; 
        ListNode* prev1 = nullptr; 
        ListNode* next2 = (l2)?(l2 -> next):(nullptr); 
        while(l2) {
            if (l1 && l2) {
                if (l1 -> val >= l2 -> val) {
                    if (prev1) {
                        prev1 -> next = l2; 
                    } else {
                        head = l2; 
                    }
                    prev1 = l2; 
                    l2 -> next = l1; 
                    l2 = next2; 
                    if (next2) {
                        next2 = l2 -> next; 
                    }
                } else {
                    prev1 = l1; 
                    l1 = l1 -> next;
                }
            }
            
            if (!l1) {
                prev1 -> next = l2; 
                break;
            }
        }
        
        return head; 
    }
};



// if (!l1) {
//             return l2;
//         }
        
//         if (!l2) {
//             return l1; 
//         }
//         ListNode* res = l1; 
//         ListNode* prev1 = nullptr; 
//         ListNode* next1 = l1 -> next;
//         ListNode* prev2 = nullptr; 
//         ListNode* next2 = l2 -> next; 
//         while(l1 || l2) {
//             if (l1 && l2 && l1 -> val > l2 -> val) {
//                 if (prev1) {
//                     prev1 -> next = l2; 
//                     prev1 = l2;
//                 }
//                 next2 = l2 -> next; 
//                 l2 -> next = l1; 
//                 l2 = next2; 
//                 next2 = l2 -> next; 
                
//             }
            
//             if (!l2) {
//                 break; 
//             }
//             if (l1 && l2 && l1 -> val <= l2 -> val) {
//                 prev1 = l1; 
//                 l1 = l1 -> next; 
//             }
            
//             if (!l1) {
//                 prev1 -> next = l2;
//                 break; 
//             }
//         }
        
//         return res; 