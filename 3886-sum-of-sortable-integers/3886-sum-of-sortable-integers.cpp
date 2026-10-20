class Solution {
public:
    int sortableIntegers(vector<int>& a) {
        int n = a.size(), res = 0;

        function<bool(int)> yes = [&](int k) {
            int gmx = 0, mn, mx;

            for (int i = 0; i < n; i += k) {
                int fall = 0;
                mn = mx = a[i];

                for (int j = i + 1; j < i + k; j++) {
                    fall += (a[j - 1] > a[j]);
                    mx = max(mx, a[j]);
                    mn = min(mn, a[j]);
                }

                fall += (a[i + k - 1] > a[i]);
                if (fall > 1 || mn < gmx) {
                    return false;
                }
                gmx = mx;
            }

            return true;
        };

        for (int i = 1; i * i <= n; i++) {
            if (n % i) {
                continue;
            }

            if (yes(i)) {
                res += i;
            }
            if (i * i != n && yes(n / i)) {
                res += n / i;
            }
        }
        return res;
    }
};