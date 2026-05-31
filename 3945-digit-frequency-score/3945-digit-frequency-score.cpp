class Solution {
public:
    int digitFrequencyScore(int n) {
        int t = n;
        vector<int> f(10);

        while (t) {
            f[t % 10]++;
            t /= 10;
        }

        int res = 0;
        for (int i = 1; i < 10; i++) {
            res += i * f[i];
        }
        return res;
    }
};