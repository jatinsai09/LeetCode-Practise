class Solution {
#define ll long long int
public:
    ll dp[30][2][2][20];

    ll find(string& s, int ind, bool tight, bool lz, int prev, int k) {
        if (ind == s.size()) {
            return 1;
        }

        if (dp[ind][tight][lz][prev + 1] != -1) {
            return dp[ind][tight][lz][prev + 1];
        }

        int ub = (tight ? s[ind] - '0' : 9);

        ll res = 0;
        for (int d = 0; d <= ub; d++) {
            bool next_tight = tight && (d == ub);
            bool next_lz = lz && (d == 0);

            if (lz) {
                res += find(s, ind + 1, next_tight, next_lz, d, k);
            } else {
                if (prev == -1) {
                    res += find(s, ind + 1, next_tight, next_lz, d, k);
                } else {
                    if (abs(d - prev) <= k) {
                        res += find(s, ind + 1, next_tight, next_lz, d, k);
                    }
                }
            }
        }

        return dp[ind][tight][lz][prev + 1] = res;
    }

    long long goodIntegers(long long l, long long r, int k) {
        string low = to_string(l - 1);
        string high = to_string(r);

        memset(dp, -1, sizeof(dp));
        ll left = find(low, 0, true, true, -1, k);

        memset(dp, -1, sizeof(dp));
        ll right = find(high, 0, true, true, -1, k);

        return right - left;
    }
};