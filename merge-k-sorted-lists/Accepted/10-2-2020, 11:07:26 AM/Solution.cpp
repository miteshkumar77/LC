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
        ListNode* res = nullptr;
        ListNode* n = nullptr;
        while(l1 || l2) {
            ListNode* nxt = nullptr;
            if (l1 && (!l2 || l1 -> val <= l2 -> val)) {
                nxt = l1;
                l1 = l1 -> next;
            } else {
                nxt = l2;
                l2 = l2 -> next;
            }
            if (n) {
                n -> next = nxt;
            } else {
                res = nxt;
            }
            n = nxt;
        }
        return res;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        function<ListNode*(int,int)> mergeUtil = [&](int i, int j) -> ListNode* {
            
            if (i > j) {
                return nullptr;
            }
            
            int mid = i + (j - i)/2;
            return merge(merge(mergeUtil(i, mid - 1), mergeUtil(mid + 1, j)), lists[mid]);
        };
        return mergeUtil(0, lists.size() - 1);
    }
};