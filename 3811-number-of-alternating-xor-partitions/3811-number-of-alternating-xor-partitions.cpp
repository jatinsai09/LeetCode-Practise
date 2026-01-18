class Solution {
#define ll long long int
const ll mod = 1e9 + 7;    
public:
    int alternatingXOR(vector<int>& a, int t1, int t2) {
        ll n = a.size();
        vector<ll> dp1(2e5 + 5), dp2(2e5 + 5);
        dp2[0] = 1;
        ll r1 = 0, r2 = 0, xr = 0;

        for (const auto& i: a) {
            xr ^= i;
            r1 = dp2[xr ^ t1];
            r2 = dp1[xr ^ t2];

            dp1[xr] += r1;
            dp1[xr] %= mod;

            dp2[xr] += r2;
            dp2[xr] %= mod;
        }

        return (r1 + r2) % mod;
    }
};