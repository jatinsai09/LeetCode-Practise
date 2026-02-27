class Solution {
public:
    int ceilD(int a, int b){
        return (a + b - 1) / b;
    }
    int minOperations(string s, int k) {
        int n = s.size(), c0 = 0;
        for (auto &c: s) {
            c0 += (c == '0');
        }

        if (c0 == 0) {
            return 0;
        }

        if (n == k) {
            return (c0 == n ? 1 : -1);
        }

        int c1 = n - c0, res = INT_MAX;

        if (c0 % 2 == 0) {
            int got = max(ceilD(c0, k), ceilD(c0, n - k));
            if (got % 2 == 1) {
                got++;
            }
            res = min(res, got);
        }

        if (c0 % 2 == k % 2) {
            int got = max(ceilD(c0, k), ceilD(c1, n - k));
            if (got % 2 == 0) {
                got++;
            }
            res = min(res, got);
        }

        return (res == INT_MAX ? -1 : res);
    }
};