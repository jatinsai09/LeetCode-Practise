class Solution {
#define ll long long    
public:
    ll nCr(ll n, ll r, ll hi) {
        if (r < 0 || r > n) {
            return 0;
        }
        if (r == 0 || r == n) {
            return 1;
        }

        r = min(r, n - r);
        ll res = 1;
        for (ll i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > hi) {
                return hi;
            }
        }
        return res;
    }
    long long nthSmallest(long long n, int k) {
        ll res = 0;
        for (ll b = 50; b >= 0 && k > 0; b--) {
            ll c = nCr(b, k, n);
            if (c < n) {
                n -= c;
                res |= (1LL << b);
                k--;
            }
        }

        return res;
    }
};