# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self,curr,num):
        if curr is None:
            return 0
        num=num*10+curr.val
        if not curr.left  and not curr.right:
            return num
        return self.dfs(curr.left,num)+self.dfs(curr.right,num)


        

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root,0)





        