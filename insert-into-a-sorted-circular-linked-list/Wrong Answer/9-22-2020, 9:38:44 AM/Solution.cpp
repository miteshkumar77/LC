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
            Node* tmp = new Node(insertVal); tmp -> next = tmp;
            return tmp;
        }
        Node* next = head -> next; 
        // if (next == head) {
        //     head -> next = new Node(insertVal, head); 
        //     return head;
        // } 
        Node* ret = head; 
        while(!(next -> val >= insertVal && head -> val <= insertVal) && next != ret) {
            head = next;
            next = next -> next; 
        }
        head -> next = new Node(insertVal, next); 
        return ret; 
    }
};