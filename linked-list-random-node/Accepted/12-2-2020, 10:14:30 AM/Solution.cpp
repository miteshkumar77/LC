// https://leetcode.com/problems/linked-list-random-node

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        len = 0;
        root = head;
        while(head) {
            ++len;
            head = head -> next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int r = rand() % len;
        ListNode* head = root;
        while(r != 0) {
            --r;
            head = head -> next;
        }
        return head -> val;
    }
private:
    int len;
    ListNode* root;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */