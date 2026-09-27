class Solution {
#define ll long long int
public:
    long long maxEarnings(vector<vector<int>>& mt) {
        ll n = mt.size();

        sort(begin(mt), end(mt), [&](auto& m1, auto& m2){
            return m1[0] < m2[0];
        });

        vector<int> byEnd(n);
        for (int i = 0; i < n; i++) {
            byEnd[i] = i;
        }

        sort(begin(byEnd), end(byEnd), [&](auto& i, auto &j){
            return mt[i][1] < mt[j][1];
        });

        int p = 0;
        vector<ll> dp(n);
        ll mx = INT_MIN, res = 0;
        for (int i = 0, j; i < n; i++) {
            while (p < n && mt[byEnd[p]][1] <= mt[i][0]) {
                j = byEnd[p++];
                mx = max(mx, dp[j] - mt[j][1]);
            }

            dp[i] = mt[i][2];
            if (mx != INT_MIN) {
                dp[i] = max(dp[i], mt[i][2] + mt[i][0] + mx);
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};