class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp((1 << n), -1);

        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }

        if (sum % k) {
            return false;
        }

        sort(rbegin(nums), rend(nums));
        if (nums[0] > sum / k) {
            return false;
        }
        int req = sum / k;

        dp[0] = 0;
        for (int i = 0; i < (1 << n); i++) {
            if (dp[i] == -1) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (!(i & (1 << j)) && dp[i] + nums[j] <= req) {
                    dp[i | (1 << j)] = (dp[i] + nums[j]) % req;
                }
            }
        }

        return dp[(1 << n) - 1] == 0;
    }
};