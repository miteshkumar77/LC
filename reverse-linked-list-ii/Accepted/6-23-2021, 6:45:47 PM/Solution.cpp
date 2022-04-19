// https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverse(ListNode* l, ListNode * h) {
        ListNode* tmp;
        while(l) {
            tmp = l -> next;
            l -> next = h;
            h = l;
            l = tmp;
        }
        return  h;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* h = head;
        ListNode* n = nullptr;
        ListNode* r = nullptr;
        for (int i = 1; i <= right; ++i) {
            if (i + 1 == left) {
                n = h;
            }
            if (i == right) {
                r = h;
            }
            h = h -> next;
        }
        // cout << n -> val << ' ' << r -> val << endl;
        auto tmp = r -> next;
        r -> next = nullptr;
        auto nh = reverse(n ? n->next : head, tmp);
        if (n) {
            n -> next = nh;
            return head;
        } else {
            return nh;
        }
    }
};