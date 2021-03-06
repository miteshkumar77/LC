// https://leetcode.com/problems/inorder-successor-in-bst-ii

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
        if (node -> right) {
            node = node -> right; 
            while(node -> left) {
                node = node -> left; 
            }
            return node; 
        } else {
            while(node && node -> parent && node -> parent -> right == node) {
                node = node -> parent; 
            }
            if (node) {
                node = node -> parent; 
            }
            return node; 
        }
    }
};