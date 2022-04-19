// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        helper(head); 
        return head; 
    }
    
    Node* helper(Node* head) {
        Node* cur = head; 
        Node* last = nullptr; 
        while(cur) {
            if (cur -> child) {
                Node* end = helper(cur -> child); 
                if (cur -> next) {
                    end -> next = cur -> next; 
                    cur -> next -> prev = end; 
                }
                cur -> next = cur -> child; 
                cur -> child -> prev = cur; 
                cur -> child = nullptr; 
            }
            last = cur; 
            cur = cur -> next; 
        }
        return last; 
    }
    
};