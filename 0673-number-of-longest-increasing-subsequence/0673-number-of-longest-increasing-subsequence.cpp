class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int maxi = 1, n = a.size();
        vector<int> dp(n, 1), cnt(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j] && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                } else if (a[i] > a[j] && 1 + dp[j] == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                res += cnt[i];
            }
        }
        return res;
    }
};