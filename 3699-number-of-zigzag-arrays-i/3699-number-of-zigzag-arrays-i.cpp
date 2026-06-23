class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int mod = 1e9 + 7;

        r -= l;
        int p;
        vector<int> dp(r + 1, 1); // dp[i] = number of zig-zag arrays that end with i
        for (int sz = 2; sz <= n; sz++) {
            p = 0;
            if (sz & 1) {
                for (int i = 0; i <= r; i++) {
                    int old = dp[i];
                    dp[i] = p;
                    p = (p + old) % mod;
                }
            } else {
                for (int i = r; i >= 0; i--) {
                    int old = dp[i];
                    dp[i] = p;
                    p = (p + old) % mod;
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