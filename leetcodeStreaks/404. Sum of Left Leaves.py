# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def solve(self, root: Optional[TreeNode],direction: bool):
        if root is None:
            return 0

        if root.left is None and root.right is None and direction:
            return root.val

        return self.solve(root.left,1) + self.solve(root.right,0)
    


    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:

       return self.solve(root,0)