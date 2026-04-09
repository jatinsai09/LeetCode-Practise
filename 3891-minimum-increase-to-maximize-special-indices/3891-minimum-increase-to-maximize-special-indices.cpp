class Solution {
#define ll long long int
public:
    long long minIncrease(vector<int>& a) {
        ll n = a.size(), res = 0;

        if (n % 2) {
            for (int i = 1; i + 1 < n; i += 2) {
                ll mx = max(a[i - 1], a[i + 1]) + 1;
                res += max(0LL, mx - a[i]);
            }

            return res;
        }

        ll m = (n >> 1) - 1, got, mx;
        vector<ll> pe(m + 2), so(m + 2);

        for (int i = 1, j; i <= m; i++) {
            j = 2 * i - 1;
            mx = max(a[j - 1], a[j + 1]) + 1;
            pe[i] = pe[i - 1] + max(0LL, mx - a[j]);
        }

        
        for (int i = m, j; i >= 1; i--) {
            j = 2 * i;
            mx = max(a[j - 1], a[j + 1]) + 1;
            so[i] = so[i + 1] + max(0LL, mx - a[j]);
        }

        res = -1;
        for (int i = 0; i <= m; i++) {
            ll cur = pe[i] + so[i + 1];
            if (res == -1 || cur < res) {
                res = cur;
            }
        }

        return res;
        
    }
};