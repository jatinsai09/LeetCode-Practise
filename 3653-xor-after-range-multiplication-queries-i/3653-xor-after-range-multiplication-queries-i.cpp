class Solution {
const int MOD = 1e9 + 7;
#define ll long long int
public:
    int xorAfterQueries(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i];
        }

        for (const auto& qr : queries) {
            int l = qr[0], r = qr[1];
            int k = qr[2];
            int v = qr[3];

            for (int i = l; i <= r; i += k) {
                b[i] = (1LL * b[i] * v) % MOD;
            }
        }

        ll xr = 0;
        for (const auto& i : b) {
            xr ^= i;
        }
        return (int)xr;
    }
};