class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        auto MaxNonAdjSum = [&](int l, int r) -> int {
            int prev2 = 0, prev = nums[l], cur = nums[l];

            for (int i = l + 1; i <= r; i++) {
                int pick = nums[i] + prev2, notpick = prev;

                cur = max(pick, notpick);

                prev2 = prev;
                prev = cur;
            }

            return cur;
        };

        return max(MaxNonAdjSum(0, n - 2), MaxNonAdjSum(1, n - 1));
    }
};