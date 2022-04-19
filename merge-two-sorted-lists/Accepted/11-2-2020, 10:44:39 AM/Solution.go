// https://leetcode.com/problems/merge-two-sorted-lists

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(h1 *ListNode, h2 *ListNode) *ListNode {
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