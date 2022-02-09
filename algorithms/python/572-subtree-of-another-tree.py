# https://leetcode.com/problems/subtree-of-another-tree/

from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def checkSubtree(self, node: Optional[TreeNode], subNode: Optional[TreeNode]) -> bool:
        if node is None and subNode is None:
            return True
        if node is None or subNode is None:
            return False
        if node.val != subNode.val:
            return False
        return self.checkSubtree(node.left, subNode.left) and self.checkSubtree(node.right, subNode.right)
    
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if root is None:
            return False
        if root.val == subRoot.val and self.checkSubtree(root, subRoot):
            return True
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
