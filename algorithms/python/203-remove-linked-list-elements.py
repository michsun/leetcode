# https://leetcode.com/problems/remove-linked-list-elements/

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    
    # Recursive solution
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if head is None: return None
        if head.val is val:
            head = self.removeElements(head.next, val)
        else:
            head.next = self.removeElements(head.next, val)
        return head

    # Pointer solution
    def removeElements2(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        start = ListNode()
        start.next = head
        curr = start
        
        while curr.next != None:
            if curr.next.val is val:
                curr.next = curr.next.next
            else:
                curr = curr.next
        return start.next