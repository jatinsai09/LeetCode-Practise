class Solution {
public:
    long long sum(long long n) { return (n * (n + 1)) / 2; }
    
    long long check(long long t, int wt) {
        long long l = 1, r = 1e5;
        long long maxi = 0, mid, nt;

        while (l <= r) {
            mid = (l + r) / 2;
            nt = wt * sum(mid);

            if (nt <= t) {
                //maxi = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
    long long minNumberOfSeconds(int mh, vector<int>& w) {
        long long res = 1, l = 0, r = 1e18, mid, red;
        int n = w.size();

        while (l <= r) {
            mid = (l + r) / 2;
            red = 0;
            for (int i = 0; i < n && red < mh; i++) {
                red += check(mid, w[i]);
            }

            if (red >= mh) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};