class Solution:
    def lcm(a, b):
        return abs(a * b) // gcd(a, b)

    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)

        max_length = 0

        for i in range(n):
            running_gcd = nums[i]
            running_lcm = nums[i]
            running_product = nums[i]

            for j in range(i + 1, n):
                running_gcd = gcd(running_gcd, nums[j])
                running_lcm = lcm(running_lcm, nums[j])
                running_product *= nums[j]

                if running_product == running_gcd * running_lcm:
                    max_length = max(max_length, j - i + 1)

        return max_length
