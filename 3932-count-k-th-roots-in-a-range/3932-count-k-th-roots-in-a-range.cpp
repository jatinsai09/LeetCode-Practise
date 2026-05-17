class Solution {
#define ll long long int
public:
    ll power(ll base, ll exp, ll lim) {
        ll res = 1;
        while (exp--) {
            res *= base;
            if (res > lim) {
                return lim + 1;
            }
        }
        return res;
    }

    int lowerBound(int l, int r, int k) {
        int low = 0, high = r, res = -1;
        while (low <= high) {
            int m = low + (high - low) / 2;
            ll mpk = power(m, k, r);

            if (mpk >= l) {
                res = m;
                high = m - 1;
            } else {
                low = m + 1;
            } 
        } 
        return res;
    }

    int upperBound(int l, int r, int k) {
        int low = 0, high = r, res = -1;
        while (low <= high) {
            int m = low + (high - low) / 2;
            ll mpk = power(m, k, r);

            if (mpk <= r) {
                res = m;
                low = m + 1;
            } else {
                high = m - 1;
            } 
        } 
        return res;
    }
    int countKthRoots(int l, int r, int k) {
        if (k == 1) {
            return r - l + 1;
        }

        int lo = lowerBound(l, r, k);
        int hi = upperBound(l, r, k);

        return hi - lo + 1;
    }
};