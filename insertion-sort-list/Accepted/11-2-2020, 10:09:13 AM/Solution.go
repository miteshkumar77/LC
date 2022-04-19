// https://leetcode.com/problems/insertion-sort-list

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func doASwap(head *ListNode) {
    var m *ListNode = head
    var h *ListNode = head
    for head != nil {
        if head.Val < m.Val {
            m = head
        }
        head = head.Next
    }
    m.Val, h.Val = h.Val, m.Val
    
}
func insertionSortList(head *ListNode) *ListNode {
    var h *ListNode = head
    for h != nil {
        doASwap(h)
        h = h.Next
    }
    return head
}