class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        coins = 0
        max_coins = 0
        left = 0
        right = len(tokens) - 1

        while left <= right:
            if power >= tokens[left]:
                coins += 1
                power -= tokens[left]
                left +=1
                max_coins = max(max_coins, coins)
            elif coins > 0 and power < tokens[left]:
                coins -= 1
                power += tokens[right]
                right -= 1

            else: break
                        
        return max_coins