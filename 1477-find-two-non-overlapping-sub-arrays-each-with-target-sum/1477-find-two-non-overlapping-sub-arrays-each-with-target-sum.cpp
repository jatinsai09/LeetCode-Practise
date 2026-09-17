class Solution {
public:
    int minSumOfLengths(vector<int>& a, int target) {
        int n = a.size(), res = n + 1;
        int dp[n + 1];
        dp[0] = n + 1;

        int i = 0, j = 0, sum = 0;
        while (j < n) {
            sum += a[j];

            while (sum > target) {
                sum -= a[i++];
            }

            dp[j + 1] = dp[j];

            if (sum == target) {
                int len = j - i + 1;

                res = min(res, len + dp[i]);
                dp[j + 1] = min(dp[j], len);
            }
            j++;
        }

        return (res > n ? -1 : res);
    }
};