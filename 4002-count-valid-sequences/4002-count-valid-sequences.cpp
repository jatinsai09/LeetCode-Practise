class Solution {
#define ll long long int
const ll mod = 1e9 + 7;

public:
    ll modExp(ll a, ll e, ll m) {
        a %= m;
        ll r = 1;
        while (e) {
            if (e & 1) {
                r = (r * a) % m;
            }
            a = (a * a) % m;
            e >>= 1;
        }

        return r;
    }
    int countValidSequences(int n, int k) {
        if (n == k) {
            return 0;
        }
        if (k == 1) {
            return 1 - (n & 1);
        }

        ll n1 = 1, k1 = 1, d = 1;
        {
            for (int i = n - 1; i > 0; i--) {
                n1 = (n1 * i) % mod;
            }
            for (int i = k - 1; i > 0; i--) {
                k1 = (k1 * i) % mod;
            }
            for (int i = n - k; i > 0; i--) {
                d = (d * i) % mod;
            }
        }
        ll total = (n1 * modExp((k1 * d) % mod, mod - 2, mod)) % mod;
        ll f = total;

        ll n3 = 1;
        for (int i = (n + k) / 2 - 1; i > 0; i--) {
            n3 = (n3 * i) % mod;
        }

        ll lim = (n + k) / 2 - 1 - (k - 1);
        d = 1;
        for (int i = lim; i > 0; i--) {
            d = (d * i) % mod;
        }
        
        ll s = (n3 * modExp(d * k1, mod - 2, mod)) % mod; 
        if (lim < 0 || (n - k) % 2)  {
            s = 0;
        }

        f = (f - s + mod) % mod;

        return f;
    }
};