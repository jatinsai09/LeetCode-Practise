class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        res = odd = even = 0
        for i in arr:
            even += 1
            if i % 2:
                odd, even = even, odd
            res = (res + odd) % 1000000007
        return res        

        