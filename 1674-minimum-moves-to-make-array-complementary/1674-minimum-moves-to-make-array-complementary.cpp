class Solution {
public:
    int minMoves(vector<int>& a, int limit) {
        /* For ever pair {i, n - i - 1} there are only three possibilities,
        we can replace either none, one or both of the numbers with any number
        in the range [1, limit] and possible sums are in the range [2, limit * 2] */

        int n = a.size();
        vector<int> dp(limit * 2 + 2);
        for (int i = 0; i < n / 2; i++) {
            int mn = min(a[i], a[n - i - 1]);
            int mx = max(a[i], a[n - i - 1]);

            dp[mn + 1]--;
            dp[mx + limit + 1]++;

            dp[mn + mx]--;
            dp[mn + mx + 1]++;
        }

        int cur = n, res = n;
        for (int i = 1; i <= limit * 2; i++) {
            cur += dp[i];
            res = min(res, cur);
        }
        return res;
    }
};