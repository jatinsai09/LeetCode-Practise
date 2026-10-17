class Solution {
public:
    int digitSum(int n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    int minSwaps(vector<int>& a) {
        int n = a.size();
        vector<int> b = a;

        sort(begin(b), end(b), [&](int x, int y) {
            int sumX = digitSum(x), sumY = digitSum(y);
            if (sumX == sumY) {
                return x < y;
            }
            return sumX < sumY;
        });

        unordered_map<int, int> og;
        for (int i = 0; i < n; i++) {
            og[b[i]] = i;
        }


        vector<bool> vis(n, 0);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }

            int c = 0, j = i;
            while (!vis[j]) {
                vis[j] = 1;
                c++;
                j = og[a[j]];
            }
            swaps += (c - 1);
        }
        return swaps;
    }
};