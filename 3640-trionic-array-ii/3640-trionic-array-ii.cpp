class Solution {
#define ll long long
public:
    long long maxSumTrionic(vector<int>& a) {
        ll n = a.size(), res = LLONG_MIN, sum = a[0];
        ll l = 0, p = 0, q = 0, r = 1;
        for (; r < n; r++) {
            sum += a[r];
            if (a[r - 1] == a[r]) {
                l = r;
                sum = a[r];
            } else if (a[r] > a[r - 1]) {
                if (r > 1 && a[r - 2] > a[r - 1]) {
                    q = r - 1;
                }
                if (l < p && p < q) {
                    res = max(res, sum);
                }
            } else {
                if (r > 1 && a[r - 2] < a[r - 1]) {
                    p = r - 1;
                    while (l < q) {
                        sum -= a[l++];
                    }
                    while (l + 1 < p && a[l] < 0) {
                        sum -= a[l++];
                    }
                }
            }
        }

        return res;
    }
};