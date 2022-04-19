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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        while(l1 || l2) {
            if (!l2 || (l1 && l1 -> val <= l2 -> val)) {
                if (curr) curr -> next = l1;
                curr = l1;
                l1 = l1 -> next;
            } else {
                if (curr) curr -> next = l2;
                curr = l2;
                l2 = l2 -> next;
            }
            curr -> next = nullptr;
            if (!head) head = curr;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int e = (int)lists.size() - 1;
        
        int latest; 
        
        while(e > 0) {
            latest = 0;
            for (int i = 0; i + 1 <= e; i += 2) {
                lists[i] = merge(lists[i], lists[i + 1]); 
            }

            for (int i = 0; i <= e; i += 2) {
                swap(lists[i], lists[i/2]);
                latest = max(latest, i/2); 
            }
            e = latest;
        }
        return lists[0];
    }
};