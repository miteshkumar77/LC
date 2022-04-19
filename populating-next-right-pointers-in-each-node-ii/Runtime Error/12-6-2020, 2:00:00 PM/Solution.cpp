// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

typedef pair<Node*, int> pti;
class Solution {
public:
    Node* connect(Node* root) {
        
        queue<pti> q; 
        q.push(pti(root, 0)); 
        Node* prevNode = nullptr;
        int prevLevel = -1; 
        while(!q.empty()) {
            pti top = q.front(); q.pop(); 
            if (top.first->left) {
                q.push(pti(top.first->left,top.second+1));
            }
            if (top.first->right) {
                q.push(pti(top.first->right,top.second+1));
            }
            
            if (prevLevel == top.second) {
                prevNode->next = top.first;
            }
            prevLevel = top.second;
            prevNode = top.first;
        }
        
        return root;
    }
};