class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        int maxSum = nums[0], minSum = nums[0];
        int curMax = 0, curMin = 0;

        for (auto& i : nums) {
            curMax = max(i, curMax + i);
            maxSum = max(maxSum, curMax);

            curMin = min(i, curMin + i);
            minSum = min(minSum, curMin);

            sum += i;
        }

        if (sum == minSum) {
            return maxSum;
        }

        return max(maxSum, sum - minSum);
    }
};