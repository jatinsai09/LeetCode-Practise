class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();

        vector<tuple<int, int, int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(begin(jobs), end(jobs));

        vector<int> dp(n);
        dp[0] = get<2>(jobs[0]);
        for (int i = 1; i < n; i++) {
            auto [e, s, p] = jobs[i];

            dp[i] = dp[i - 1];

            int ind = -1, l = 0, r = i - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;

                if (s >= get<0>(jobs[m])) {
                    ind = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            if (ind != -1) {
                dp[i] = max(dp[i], p + dp[ind]);
            } else {
                dp[i] = max(dp[i], p);
            }
        }

        return dp[n - 1];
    }
};