class Solution {
public:
    int countDominantElements(vector<int>& a) {
        int n = a.size();

        if (n == 1) {
            return 1;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                res += (a[i] >= a[i + 1]);
            } else if (i == n - 1) {
                res += (a[i] >= a[i - 1]);
            } else {
                res += (a[i] * 2 >= a[i - 1] + a[i + 1]);
            }
        }

        return res;
    }
};