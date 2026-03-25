class Solution {
public:
    // int dpp[505];
    // int help(int i, int n, int k, vector<int>& nums) {
    //     if (i == n) {
    //         return 0;
    //     }
    //     if (dpp[i] != -1) {
    //         return dpp[i];
    //     }

    //     int mx = nums[i], len = 0, res = INT_MIN;
    //     for (int j = i; j < min(n, i + k); j++) {
    //         len++;
    //         mx = max(nums[j], mx);
    //         int got = 1LL * len * mx + help(j + 1, n, k, nums);
    //         res = max(res, got);
    //     }

    //     return dpp[i] = res;
    // }
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n = nums.size();
        //memset(dpp, -1, sizeof(dpp));
        int dp[n + 1];
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            int mx = nums[i], res = INT_MIN;
            for (int j = i; j < min(n, i + k); j++) {
                mx = max(nums[j], mx);
                int got = 1LL * (j - i + 1) * mx + dp[j + 1];
                res = max(res, got);
            }
            dp[i] = res;
        }
        return dp[0];
    }
};