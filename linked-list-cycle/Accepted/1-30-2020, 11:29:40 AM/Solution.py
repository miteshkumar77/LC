// https://leetcode.com/problems/linked-list-cycle

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        fast = head
        slow = head
        while(fast and fast.next):
            fast = fast.next
            fast = fast.next
            slow = slow.next
            if (fast == slow):
                return True
        return False 
    
        