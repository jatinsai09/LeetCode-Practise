class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
public:
    int distinctSubseqII(string s) {
        vector<ll> dp(26);
        ll res = 0, t = 0;

        for (const auto &c: s) {
            t = (res + 1) % mod;

            res = (res + t - dp[c - 'a'] + mod) % mod;
            dp[c - 'a'] = t;
        }

        return res;
    }
};