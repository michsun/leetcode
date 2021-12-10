/*
Link: https://leetcode.com/problems/merge-two-sorted-lists/

*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func mergeTwoLists(_ list1: ListNode?, _ list2: ListNode?) -> ListNode? {
        if list1 == nil && list2 == nil { return nil }
        else if list1 == nil && list2 != nil { return list2 }
        else if list2 == nil && list1 != nil { return list1 }
        
        var head = ListNode()
        
        var prev: ListNode? = nil
        var a: ListNode? = list1
        var b: ListNode? = list2
        if a!.val <= b!.val {
            head.val = a!.val
            a = a!.next
        } else {
            head.val = b!.val
            b = b!.next
        }
        prev = head
        while (a != nil && b != nil) {
            if a!.val <= b!.val {
                prev!.next = ListNode(a!.val)
                a = a!.next
            } else {
                prev!.next = ListNode(b!.val)
                b = b!.next
            }
            prev = prev!.next
        }
        if (a == nil && b != nil) {
            prev!.next = b
        } else if (a != nil && b == nil) {
            prev!.next = a
        }
        
        return head
    }
}