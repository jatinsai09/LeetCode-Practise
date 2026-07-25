class Solution {
public:
    bool search(vector<int>& a, int target) {
        int n = a.size(), l = 0, r = n - 1, m;

        while (l <= r) {
            m = (l + r) >> 1;

            if (a[m] == target) {
                return true;
            }

            if (a[l] == a[m] && a[m] == a[r]) {
                l++;
                r--;
            } else if(a[l] <= a[m]) {
                if (a[l] <= target && target < a[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (a[m] < target && target <= a[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return false;
    }
};