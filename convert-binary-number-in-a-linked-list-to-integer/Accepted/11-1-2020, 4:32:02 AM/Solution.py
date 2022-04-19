// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def getDecimalValue(self, head):
        num = 0
        while head:
            num = num << 1
            num = num | head.val
            head = head.next
        return num
        