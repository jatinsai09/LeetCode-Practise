class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(begin(houses), end(houses));
        int n = houses.size();

        vector<int> ps(n + 1);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + houses[i - 1];
        }

        int dp[100][100];
        memset(dp, -1, sizeof(dp));

        function<int(int, int)> f = [&](int i, int k) -> int {
            if (i == n) {
                return 0;
            }

            if (dp[i][k] != -1) {
                return dp[i][k];
            }

            int res = INT_MAX;
            if (k == 1) {
                int mi = (i + n - 1) / 2, mh = houses[mi];

                int cost = (mi - i + 1) * mh - (ps[mi + 1] - ps[i]) +
                    (ps[n - 1 + 1] - ps[mi + 1]) - (n - 1 - mi) * mh;

                return dp[i][k] = cost;
            }

            for (int j = i; j + k <= n; j++) {
                int mi = (i + j) / 2, mh = houses[mi];

                int cost = (mi - i + 1) * mh - (ps[mi + 1] - ps[i]) +
                    (ps[j + 1] - ps[mi + 1]) - (j - mi) * mh;

                res = min(res, cost + f(j + 1, k - 1));
            }

            return dp[i][k] = res;
        };

        return f(0, k);
    }
};