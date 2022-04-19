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
        if (!head) {
            return nullptr; 
        }
        
        Node* tmp = head; 
        while(tmp -> next) {
            if (tmp -> child) {
                Node* nxt = tmp -> next; 
                Node* splice = helper(tmp -> child); 
                tmp -> next = tmp -> child; 
                tmp -> child -> prev = tmp; 
                tmp -> child = nullptr; 
                splice -> next = nxt; 
                nxt -> prev = splice; 
                tmp = nxt; 
            } else {
                tmp = tmp -> next; 
            }
        }
        
        
        if (tmp -> child) {
            Node* splice = flatten(tmp -> child); 
            tmp -> next = tmp -> child; 
            tmp -> child -> prev = tmp; 
            tmp -> child = nullptr; 
            return splice; 
        } else {
            return tmp; 
        }
    }
};