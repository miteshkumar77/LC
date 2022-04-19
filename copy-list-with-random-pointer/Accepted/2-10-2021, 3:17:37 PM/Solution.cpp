// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        int n = 0;
        Node* curr = head;
        while(curr) {
            ++n;
            curr = curr -> next;
        }
        curr = head;
        void* v = operator new[](n * sizeof(Node)); 
        
        Node* nodes = static_cast<Node*>(v);
        
        for (int i = 0; i < n; ++i) {
            // cout << curr -> val << ' ';
            new (nodes + i) Node(curr -> val); 
            (nodes + i) -> next = curr -> next;
            curr -> next = (nodes + i);
            curr = (nodes + i) -> next;
        }
        // cout << endl;
        curr = head;
        for (int i = 0; i < n; ++i) {
            (nodes + i) -> random = curr -> random?curr -> random -> next:nullptr;
            curr = (nodes + i) -> next;
        }
        curr = head;
        for (int i = 0; i < n; ++i) {
            curr -> next = (nodes + i) -> next;
            curr = curr -> next;
            if (i < n - 1) {
                (nodes + i) -> next = (nodes + i + 1);
            } else {
                (nodes + i) -> next = nullptr;
            }
        }
        curr = head;
        while(curr) {
            cout << curr -> val << ", ";
            cout << ((curr -> random)?(curr->random->val):-1) << " ";
            curr = curr -> next;
        }
        return nodes;
    }
};