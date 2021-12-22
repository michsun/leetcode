// https://leetcode.com/problems/search-in-a-binary-search-tree/

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
    func searchBST(_ root: TreeNode?, _ val: Int) -> TreeNode? {
        if (root == nil) { return nil }
        if (root!.val == val ) { return root }
        var root = (root!.val > val) ? searchBST(root!.left, val) : searchBST(root!.right, val)
        return root
    }
    
    // Iterative solution
    func searchBST2(_ root: TreeNode?, _ val: Int) -> TreeNode? {
        var root = root
        while (root != nil && root!.val != val) {
            root = (root!.val > val) ? root!.left : root!.right
        }
        return root
    }
}
