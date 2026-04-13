class Solution {
public:
    int nthUglyNumber(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if (n == 1) {
            return 1;
        }

        int p2 = 0, p3 = 0, p5 = 0;
        vector<int> v(n);
        v[0] = 1;

        for (int i = 1; i < n; i++) {
            v[i] = min({v[p2] * 2, v[p3] * 3, v[p5] * 5});

            if (v[i] == v[p2] * 2) {
                ++p2;
            }
            if (v[i] == v[p3] * 3) {
                ++p3;
            }
            if (v[i] == v[p5] * 5) {
                ++p5;
            }
        }

        return v[n - 1];
    }
};