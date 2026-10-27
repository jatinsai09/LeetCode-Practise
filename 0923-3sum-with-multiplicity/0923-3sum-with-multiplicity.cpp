class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
public:
    int threeSumMulti(vector<int>& a, int target) {
        ll n = a.size(), res = 0;

        sort(begin(a), end(a));

        for (int i = 0; i + 2 < n; i++) {
            int j = i + 1, k = n - 1;

            while (j < k) {
                ll sum = a[i] + a[j] + a[k];

                if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    ll c1 = 0, c2 = 0;
                    int jj = j, kk = k;
                    while (jj < k && a[jj] == a[j]) {
                        c1++;
                        jj++;
                    }
                    while (kk >= jj && a[kk] == a[k]) {
                        c2++;
                        kk--;
                    }

                    if (a[j] == a[k]) {
                        res += c1 * (c1 + 1) / 2;
                        res %= mod;
                    } else {
                        res += c1 * c2;
                        res %= mod;
                    }
                    j = jj;
                    k = kk;
                }
            }
        }

        return res % mod;
    }
};