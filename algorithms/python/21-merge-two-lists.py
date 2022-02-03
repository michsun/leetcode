# https://leetcode.com/problems/merge-two-sorted-lists/

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    
    # Recursive solution
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if list2 is None: return list1
        
        newHead = ListNode()
        if list1.val <= list2.val:
            newHead.val = list1.val
            newHead.next = self.mergeTwoLists(list1.next, list2)
        else: 
            newHead.val = list2.val
            newHead.next = self.mergeTwoLists(list1, list2.next)
        return newHead
        
