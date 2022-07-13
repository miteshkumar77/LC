/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            node = node->right;
            while(node->left)
                node = node->left;
            return node;
        } else {
            while(node) {
                if (!node->parent) {
                    return nullptr;
                } else if (node->parent->right == node) {
                    node = node->parent;
                } else {
                    node = node->parent;
                    return node;
                }
            }
            return node;
        }
    }
};