// https://leetcode.com/problems/print-immutable-linked-list-in-reverse

/*   Below is the interface for ImmutableListNode, which is already defined for you.
 *
 *   type ImmutableListNode struct {
 *       
 *   }
 *
 *   func (this *ImmutableListNode) getNext() ImmutableListNode {
 *		// return the next node.
 *   }
 *
 *   func (this *ImmutableListNode) printValue() {
 *		// print the value of this node.
 *   }
 */

func printUtil(head ImmutableListNode, end ImmutableListNode) {
    
    if head == end {
        head.printValue()
        return
    }
    
    var slow ImmutableListNode = head
    var fast ImmutableListNode = head
    var prev ImmutableListNode = nil
    
    for fast != end {
        prev = slow 
        slow = slow.getNext()
        fast = fast.getNext()
        if fast != end {
            fast = fast.getNext()
        }
    }
    printUtil(slow, end)
    printUtil(head, prev)
}

func printLinkedListInReverse(head ImmutableListNode) {
    var tail ImmutableListNode = head
    for tail.getNext() != nil {
        tail = tail.getNext()
    }
    printUtil(head, tail)
}