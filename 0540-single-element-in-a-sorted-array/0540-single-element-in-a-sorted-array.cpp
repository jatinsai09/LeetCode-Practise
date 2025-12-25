class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size(), l = 0, r = n - 1, m;

        while (l < r) {
            m = (l + r) >> 1;

            if ((m % 2 == 0 && a[m] == a[m + 1]) ||
                (m % 2 && a[m] == a[m - 1])) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return a[r];
    }
};