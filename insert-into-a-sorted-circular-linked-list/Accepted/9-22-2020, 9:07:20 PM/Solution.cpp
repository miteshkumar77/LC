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
    
    void ins(Node* head, int iv) {
        Node* pr = head;
        Node* h = head -> next;
        while(h && !(h -> val >= iv && pr -> val <= iv)) {
            pr = h;
            h = h -> next;
        }
        pr -> next = new Node(iv, h); 
    }
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* ret = new Node(insertVal); 
            ret -> next = ret; 
            return ret; 
        }
        
        
        Node* node = head -> next;
        Node* prev = head; 
        while(node != head && node -> val >= prev -> val) {
            prev = node;
            node = node -> next; 
        }
        prev -> next = nullptr; 
        ins(node, insertVal); 
        while(prev -> next) {
            prev = prev -> next;
        }
        prev -> next = node;
        return head; 
    }
};