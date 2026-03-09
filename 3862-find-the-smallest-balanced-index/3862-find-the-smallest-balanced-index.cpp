class Solution {
#define ll long long
public:
    int smallestBalancedIndex(vector<int>& a) {
        int n = a.size();
        ll mx = 1e5 * 1e9 + 7LL;
        vector<ll> ps(n), sm(n);
        
        ps[0] = a[0];
        for (int i = 1; i < n; i++) {
            ps[i] = a[i] + ps[i - 1];
        }
        ll sum = ps[n - 1];

        sm[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (sm[i + 1] >= mx / a[i] + 1) {
                sm[i] = mx;
                continue;
            }
            sm[i] = a[i] * sm[i + 1];
        }

        for (int i = 0; i < n; i++) {
            ll l = (i == 0 ? 0 : ps[i - 1]);
            ll r = (i == n - 1 ? 1 : sm[i + 1]);

            if (l == r) {
                return i;
            } 
        }
        return -1;
    }
};