class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), res = 0, mn = INT_MAX;
        vector<int> dp(n + 1);

        for (auto &item: items) {
            mn = min(mn, item[1]);
            dp[item[0]]++;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i * 2; j <= n; j += i) {
                dp[i] += dp[j];
            }
        }

        sort(begin(items), end(items), [&](auto& a, auto& b){
            return a[1] < b[1];
        });

        for (auto &i: items) {
            if (i[1] < 2 * mn) {
                int t = min(dp[i[0]] - 1, budget / i[1]);
                budget -= t * i[1];
                res += t * 2;
            }
        }
        return res + budget / mn;
    }
};