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
        
        Node* next = head -> next; 
        Node* prev = head;
        
        int pv = prev -> val;
        int nv = next -> val; 
        while(pv < nv && !(pv <= insertVal && nv >= insertVal)) {
            prev = next;
            next = next -> next;
            pv = nv;
            nv = next -> val;
        }
        prev -> next = new Node(insertVal, next); 
        return head; 
    }
};