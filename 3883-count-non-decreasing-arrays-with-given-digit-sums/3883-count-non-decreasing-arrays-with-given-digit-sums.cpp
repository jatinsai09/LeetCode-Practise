class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
const int N = 5000;
public:
    int countArrays(vector<int>& ds) {
        ll n = ds.size();

        vector<int> s(N + 1);
        for (int i = 0; i <= N; i++) {
            int got = 0, t = i;
            while (t) {
                got += t % 10;
                t /= 10;
            }
            s[i] = got;
        }

        vector<ll> dp(N + 1);
        for (int i = 0; i <= N; i++) {
            if (s[i] == ds[0]) {
                dp[i] = 1;
            }
        }


        for (int i = 1; i < n; i++) {
            vector<ll> dp1(N + 1);
            ll got = 0;
            for (int j = 0; j <= N; j++) {
                got = (got + dp[j]) % mod;
                if (s[j] == ds[i]) {
                    dp1[j] = got;
                }
            }
            dp = dp1;
        }

        ll res = 0;
        for (int i = 0; i <= N; i++) {
            res = (res + dp[i]) % mod;
        }

        return res;
    }
};