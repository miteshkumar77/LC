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
    
    
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        
        while(h1 || h2) {
            ListNode* nxt = nullptr;
            if (h1 && (!h2 || h2 -> val > h1 -> val)) {
                nxt = h1;
                h1 = h1 -> next;
            } else {
                nxt = h2;
                h2 = h2 -> next;
            }
            nxt -> next = nullptr;
            if (curr) {
                curr -> next = nxt;
            } else {
                head = nxt;
            }
            curr = nxt;
        }
        return head;
    }
    
    pair<ListNode*, ListNode*> split(ListNode* head) {
        ListNode* h1 = nullptr;
        ListNode* c1 = nullptr;
        ListNode* c2 = nullptr;
        ListNode* h2 = nullptr;
        
        bool h = false;
        while(head) {
            if (h) {
                if (c1) {
                    c1 -> next = head;
                } else {
                    h1 = head;
                }
                c1 = head;
            } else {
                if (c2) {
                    c2 -> next = head;
                } else {
                    h2 = head;
                }
                c2 = head;
            }
            h = !h;
            head = head -> next;
        }
        c1 -> next = nullptr;
        c2 -> next = nullptr;
        return make_pair(h1, h2);
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }
        
        // ListNode* tmp = new ListNode(4);
        // tmp -> next = new ListNode(1);
        
        
        
        // auto p = split(tmp);
//         auto p = make_pair(tmp, nullptr);
//         p.first = merge(p.first, p.second);
//         while(p.first) {
//             cout << p.first -> val << ' ';
//             p.first = p.first -> next;
//         }
//         cout << endl;
        
//         // while(p.second) {
//         //     cout << p.second -> val << ' ';
//         //     p.second = p.second -> next;
//         // }
        
//         return p.second;
        // ListNode* a = new ListNode(4);
        // ListNode* b = new ListNode(5);
        // a -> next = new ListNode(6);
        // return merge(a, b);
        
        auto p = split(head);
        p.first = sortList(p.first);
        p.second = sortList(p.second);
        return merge(p.first, p.second);
        
    }
};