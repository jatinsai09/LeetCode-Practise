class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int mod = 1e9 + 7;

        r -= l;
        int p;
        vector<int> dp(r + 1, 1);
        for (int k = 1; k < n; k++) {
            p = 0;
            if (k & 1) {
                for (int i = 0; i <= r; i++) {
                    int old = dp[i];
                    dp[i] = p;
                    p += old;
                    p %= mod;
                }
            } else {
                for (int i = r; i >= 0; i--) {
                    int old = dp[i];
                    dp[i] = p;
                    p += old;
                    p %= mod;
                }
            }
        }

        p = 0;
        for (auto& i : dp) {
            p += i;
            p %= mod;
        }

        return (p * 2) % mod;
    }
};