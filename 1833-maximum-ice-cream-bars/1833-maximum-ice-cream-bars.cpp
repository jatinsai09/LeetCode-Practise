class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size(), mx = 0;
        for (auto &i: costs) {
            mx = max(mx, i);
        }

        vector<int> f(mx + 1);
        for (auto &i: costs) {
            f[i]++;
        }

        int res = 0;
        for (int c = 1; c <= mx; c++) {
            if (f[c] == 0) {
                continue;
            }

            int got = min(f[c], coins / c);

            if (got == 0) {
                break;
            }

            res += got;
            coins -= got * c;
        }

        return res;
    }
};