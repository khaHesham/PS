# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.diameter = 0
    def solve(self,root: Optional[TreeNode]):
        if root is None:
            return 0
        max_left = self.solve(root.left)
        max_right = self.solve(root.right)
        self.diameter = max(self.diameter,max_right + max_left)
        return 1 + max(max_left,max_right )

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.solve(root)
        return self.diameter 
        