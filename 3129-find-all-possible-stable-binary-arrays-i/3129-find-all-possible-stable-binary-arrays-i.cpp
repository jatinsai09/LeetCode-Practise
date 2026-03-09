class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<ll>> dp0(zero + 1, vector<ll>(one + 1)), dp1(dp0);

        for (int i = 0; i <= min(limit, zero); i++) {
            dp0[i][0] = 1;
        }
        for (int j = 0; j <= min(limit, one); j++) {
            dp1[0][j] = 1;
        }

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                ll g0 = dp0[i - 1][j] + dp1[i - 1][j];
                if (i - 1 - limit >= 0) {
                    g0 -= dp1[i - 1 - limit][j];
                }
                dp0[i][j] = (g0 % mod + mod) % mod;

                ll g1 = dp0[i][j - 1] + dp1[i][j - 1];
                if (j - 1 - limit >= 0) {
                    g1 -= dp0[i][j - 1 - limit];
                }
                dp1[i][j] = (g1 % mod + mod) % mod;
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % mod;
    }
};