class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
public:
    int maxSum(vector<int>& a, int k) {
        ll n = a.size(), bc[30] = {0};

        for (auto &i: a) {
            for (int b = 0; b < 30; b++) {
                if ((i >> b) & 1) {
                    bc[b]++;
                }
            }
        }

        ll res = 0;
        while (k--) {
            ll got = 0;
            for (int b = 0; b < 30; b++) {
                if (bc[b]) {
                    got += (1 << b);
                    bc[b]--;
                }
            }

            res += (got * got) % mod;
            res %= mod;
        }

        return res;
    }
};