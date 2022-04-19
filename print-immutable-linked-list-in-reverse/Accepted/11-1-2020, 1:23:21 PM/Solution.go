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

func get(head ImmutableListNode, end ImmutableListNode) ImmutableListNode {
    var prev ImmutableListNode = nil
    for head != end {
        prev = head
        head = head.getNext()
    }
    return prev
}

func printLinkedListInReverse(head ImmutableListNode) {
    var end ImmutableListNode = nil
    for {
        end = get(head, end)
        if end == nil {
            break;
        }
        end.printValue();
    }
}