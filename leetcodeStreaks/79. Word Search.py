class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def solve(i: int, j: int,k: int) -> bool:
            if k == len(word):
                return True
        
            if i < 0 or i >=len(board) or j < 0 or j >=len(board[0]) or board[i][j] != word[k]:
                return False

            temp = board[i][j]
            board[i][j] = ''

            if solve(i+1,j,k+1) or solve(i,j+1,k+1) or solve(i-1,j,k+1) or solve(i,j-1,k+1):
                return True

            board[i][j] = temp
            return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                if solve(i,j,0):
                    return True

        

