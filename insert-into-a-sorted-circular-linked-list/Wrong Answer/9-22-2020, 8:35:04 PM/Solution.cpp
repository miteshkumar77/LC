// https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* ret = new Node(insertVal); 
            ret -> next = ret; 
            return ret; 
        }
        
        Node* node = head -> next; 
        Node* prev = head;
        
        
        while((node != head) && !(node -> val >= insertVal && prev -> val <= insertVal)) {
            prev = node; 
            node = node -> next; 
        }
        
        prev -> next = new Node(insertVal, node); 
        return head; 
    }
};