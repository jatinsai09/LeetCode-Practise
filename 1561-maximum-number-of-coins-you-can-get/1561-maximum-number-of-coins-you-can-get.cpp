class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size(), mx = piles[0];
        for (auto &i: piles) {
            mx = max(mx, i);
        }

        vector<int> f(mx + 1);
        for (auto &i: piles) {
            f[i]++;
        }

        int get = n / 3, turn = 0, i = mx, res = 0;
        while (get) {
            if (f[i]) {
                res += i * turn;
                get -= turn;
                turn ^= 1;

                f[i]--;
            } else {
                i--;
            }
        }

        return res;
    }
};