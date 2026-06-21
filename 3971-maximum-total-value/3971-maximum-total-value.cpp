class Solution {
public:
#define ll long long int
static const int MOD = 1e9 + 7;
    ll add(ll a, ll b, ll m = MOD) { return ((a % m) + (b % m) + m) % m; };
    ll sub(ll a, ll b, ll m = MOD) { return ((a % m) - (b % m) + m) % m; };
    ll mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; };
    ll modExp(ll a, ll e, ll m = MOD) {
        a %= m;
        ll r = 1;
        while (e) {
            if (e & 1) {
                r = mul(r, a, m);
            }
            a = mul(a, a, m);
            e >>= 1;
        }

        return r;
    }
    ll invf(ll a, ll m = MOD) { return modExp(a, m - 2, m); }
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int n = value.size();

        ll l = 0, r = 1e9, best = 0, mid;
        auto cnt_f = [&](ll t) -> ll {
            ll cnt = 0;
            for (int i = 0; i < n; i++) {
                if (value[i] < t) {
                    continue;
                }
                cnt += ((1LL * value[i] - t) / decay[i]) + 1;
            }

            return cnt;
        };


        while (l <= r) {
            mid = l + (r - l) / 2;

            if (cnt_f(mid) >= m) {
                best = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        ll res = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (value[i] < best + 1) {
                continue;
            }

            ll k = ((1LL * value[i] - (best + 1)) / decay[i]) + 1;
            cnt += k;
            k %= MOD;

           res = add(res,
                    mul(
                        mul(
                            sub(
                                mul(value[i], 2),
                                mul(decay[i], sub(k, 1))
                            ),
                            k
                        ),
                        invf(2)
                    )
                );
        }
        res = add(res, 
                mul(
                    best, 
                    sub(m, cnt)
                )
            );

        return res;
    }
};