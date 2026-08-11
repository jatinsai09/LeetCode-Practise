class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n = a.size();

        if (n < 3) {
            return 0;
        }

        int res = 0, i = 1;
        while (i + 1 < n) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                int l = i, r = i;

                while (l > 0 && a[l - 1] < a[l]) {
                    l--;
                }
                while (r + 1 < n && a[r + 1] < a[r]) {
                    r++;
                }

                res = max(res, r - l + 1);

                i = r + 1;
            } else {
                i++;
            }
        }
        return res;
    }
};