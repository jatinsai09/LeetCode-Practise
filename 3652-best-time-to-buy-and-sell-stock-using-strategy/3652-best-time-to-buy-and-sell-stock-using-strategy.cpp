class Solution {
public:
    long long maxProfit(vector<int>& p, vector<int>& s, int k) {
        int n = p.size(), k2 = (k >> 1);

        vector<long long> pref(n), sum(n);
        pref[0] = p[0] * s[0];
        sum[0] = p[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + p[i] * s[i];
            sum[i] = sum[i - 1] + p[i];
        }

        long long got, res = pref[n - 1], total = pref[n - 1];
        for (int i = k - 1; i < n; i++) {
            got = total - pref[i] + (i - k >= 0 ? pref[i - k] : 0);
            got += (sum[i] - sum[i - k2]);

            res = max(res, got);
        }

        return res;
    }
};