// https://leetcode.com/problems/print-immutable-linked-list-in-reverse

/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    
    ImmutableListNode* get(ImmutableListNode* head, ImmutableListNode* end) {
        ImmutableListNode* prev = nullptr;
        while(head != end) {
            prev = head;
            head = head -> getNext();
        }
        return prev;
    }
    
    void printLinkedListInReverse(ImmutableListNode* head) {
        ImmutableListNode* end = nullptr;
        do {
            end = get(head, end);
            if (end) end -> printValue();
        } while(end); 
        
    }
};