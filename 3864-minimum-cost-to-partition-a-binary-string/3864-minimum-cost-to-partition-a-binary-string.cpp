class Solution {
#define ll long long
public:
    long long minCost(string s, int ec, int fc) {
        ll n = s.size();
        vector<ll> ps(n + 1);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = (s[i] - '0') + ps[i];
        }

        function<ll(int, int)> give = [&](int l, int r) -> ll {
            ll len = r - l + 1, hv = ps[r + 1] - ps[l];

            ll og = (hv ? len * hv * ec : fc);

            if (len & 1) {
                return og;
            }

            ll m = (l + r) / 2;
            ll got = give(l, m) + give(m + 1, r);

            return min(og, got);
        };

        return give(0, n - 1);
    }
};