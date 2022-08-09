/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode* node) {
        int ans{0};
        while(node) {
            ++ans;
            node = node->next;
        }
        return ans;
    }
    ListNode* advance(ListNode* node, int k) {
        while(node && k--) {
            node = node->next;
        }
        return node;
    }
    ListNode* meet(ListNode* a, ListNode* b) {
        while(a && b && a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = len(headA);
        int lenB = len(headB);
        if (lenA < lenB) {
            headB = advance(headB, lenB-lenA);
        } else {
            headA = advance(headA, lenA-lenB);
        }
        
        return meet(headA, headB);
    }
};