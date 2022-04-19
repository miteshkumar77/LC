// https://leetcode.com/problems/insertion-sort-list

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func merge(h1 *ListNode, h2 *ListNode) *ListNode {
    var head *ListNode = nil
    var next *ListNode = nil
    var prev *ListNode = nil
    for h1 != nil || h2 != nil {
        if h1 != nil && (h2 == nil || h2.Val > h1.Val) {
            next = h1
            h1 = h1.Next
        } else {
            next = h2
            h2 = h2.Next
        }
        
        if head != nil {
            prev.Next = next
            prev = next
        }
        
        if head == nil {
            head = next
            prev = next
        }
        next.Next = nil
        
    }
    return head
}

func split(head *ListNode) (*ListNode, *ListNode) {
    var slow *ListNode = head
    var fast *ListNode = head
    var prev *ListNode = nil
    
    for fast != nil {
        prev = slow
        slow = slow.Next
        fast = fast.Next
        if fast != nil {
            fast = fast.Next
        }
    }
    prev.Next = nil
    return head, slow
}

func insertionSortList(head *ListNode) *ListNode {
    if (head == nil || head.Next == nil) {
        return head
    }
    
    h1, h2 := split(head)
    h1 = insertionSortList(h1)
    h2 = insertionSortList(h2)
    return merge(h1, h2)
    
}