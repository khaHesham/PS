class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        num_freq = Counter(nums)
        max_freq = max(num_freq.values())
        total_freq = max_freq * len([num for num, freq in num_freq.items() if freq == max_freq])

        return total_freq