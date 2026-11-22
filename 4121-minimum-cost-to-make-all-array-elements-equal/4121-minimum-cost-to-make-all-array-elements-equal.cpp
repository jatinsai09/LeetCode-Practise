class Solution {
#define ll long long int
public:
    long long minCost(vector<int>& a) {
        ll n = a.size();

        vector<ll> l(n), r(n);
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                l[i] = l[i - 1];
            } else {
                l[i] = 1LL * a[i] * i;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] == a[i + 1]) {
                r[i] = r[i + 1];
            } else {
                r[i] = 1LL * a[i] * (n - i - 1);
            }
        }

        ll res = LLONG_MAX;
        for (int i = 1; i + 1 < n; i++) {
            res = min(res, l[i] + r[i]);
        }

        return res;
    }
};