class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size(), l = 0, r = n - 1, m;

        while (l < r) {
            m = (r + l) >> 1;

            if (a[m] > a[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return a[r];
    }
};