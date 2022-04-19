// https://leetcode.com/problems/reverse-linked-list

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        p1 = head
        p2 = None
        p3 = None
        
        if p1:
            p2 = p1.next
            if p2:
                p3 = p2.next
        else:
            return p1
        p1.next = None
        
        while p2:
            p2.next = p1
            p1 = p2
            p2 = p3
            if p3:
                p3 = p3.next 
        
        return p1
        