class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        if (n == 1) {
            return 0;
        }

        if (a[0] > a[1]) {
            return 0;
        }
        if (a[n - 1] > a[n - 2]) {
            return n - 1;
        }

        int l = 1, r = n - 1, m;
        while (l < r) {
            m = l + (r - l) / 2;

            if (a[m] < a[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return r;
    }
};