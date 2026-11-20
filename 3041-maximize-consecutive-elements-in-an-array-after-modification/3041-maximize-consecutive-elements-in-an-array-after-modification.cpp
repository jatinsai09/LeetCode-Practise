class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int mx = nums[0];
        for (auto &i: nums) {
            mx = max(mx, i);
        }

        vector<int> dp(mx + 2);
        int res = 0;
        for (auto &i: nums) {
            dp[i + 1] = 1 + dp[i];
            dp[i] = 1 + dp[i - 1];

            res = max({res, dp[i], dp[i + 1]});
        }

        return res;
    }
};