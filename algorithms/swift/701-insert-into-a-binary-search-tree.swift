// https://leetcode.com/problems/insert-into-a-binary-search-tree/

// Definition for a binary tree node.
public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init() { self.val = 0; self.left = nil; self.right = nil; }
    public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
        self.val = val
        self.left = left
        self.right = right
    }
}

class Solution {
    
    // Recursive solution
    func insertIntoBST(_ root: TreeNode?, _ val: Int) -> TreeNode? {
        if (root == nil) {
            let newNode = TreeNode(val);
            return newNode
        }
        if (root!.val > val) { 
            root!.left = insertIntoBST(root!.left, val)
        }
        if (root!.val < val) {
            root!.right = insertIntoBST(root!.right, val)
        }
        return root;
    }
    
    // Iterative solution
    func insertIntoBST2(_ root: TreeNode?, _ val: Int) -> TreeNode? {
        let newNode = TreeNode(val)
        if (root == nil) { return newNode }
        
        var curr = root
        while (curr != nil) {
            if (curr!.val > val) {
                if (curr!.left == nil) {
                    curr!.left = newNode
                    curr = nil
                } else {
                    curr = curr!.left
                }
            } else if (curr!.val < val) {
                if (curr!.right == nil) {
                    curr!.right = newNode
                    curr = nil
                } else {
                    curr = curr!.right
                }
            }
        }
        return root
    }
}
