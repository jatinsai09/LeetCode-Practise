class Solution {
#define ll long long int
    const ll mod = 1e9 + 7;

public:
    ll mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; };
    ll modExp(ll a, ll e, ll m) {
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
    ll invf(ll a, ll m) { return modExp(a, m - 2, m); }
    int countVisiblePeople(int n, int pos, int k) {
        ll nm = 1, dn = 1;

        k = min(k, n - k - 1);
        for (int i = 0; i < k; i++) {
            nm = (nm * (n - i - 1)) % mod;
            dn = (dn * (i + 1)) % mod;
        }

        ll res = (nm * invf(dn, mod));

        return (res * 2) % mod;
    }
};