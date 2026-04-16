class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Set up a empty dict and a 2D array containing frequency
        count = {}
        freq = [[] for i in range(len(nums) + 1)]

        # Iterate through the array and update frequency
        # O(n)
        for num in nums:
            count[num] = 1 + count.get(num, 0)
        # Go through all frequencies and store the numbers
        # in the index of their frequencies
        # O(n)
        for num, cnt in count.items():
            freq[cnt].append(num)

        # Set up the result array, and iterate through the freq
        # list from the largest frequency to obtain the top 2
        # numbers
        # O(n)
        res = []
        for i in range(len(freq) - 1, 0, -1):
            for num in freq[i]:
                res.append(num)
                if len(res) == k:
                    return res