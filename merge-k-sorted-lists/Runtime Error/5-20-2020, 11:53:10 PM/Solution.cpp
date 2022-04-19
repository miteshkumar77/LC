// https://leetcode.com/problems/merge-k-sorted-lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(lists, 0, lists.size() - 1); 
    }
    
    ListNode* helper(vector<ListNode*>& lists, int L, int R) {
        if (L == R) {
            return lists[L]; 
        }
        
        int mid = (R - L)/2 + L; 
        ListNode* tL = helper(lists, L, mid); 
        ListNode* tR = helper(lists, mid + 1, R); 
        return mergeTwoLists(tL, tR); 
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2; 
        } else if (!l2) {
            return l1; 
        }
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