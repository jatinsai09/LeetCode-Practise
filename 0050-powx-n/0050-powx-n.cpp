class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long p = n;
        if (n < 0)
            p = -1 * p;
        while (p) {
            if (p % 2) {
                res *= x;
                p--;
            } else {
                x *= x;
                p >>= 1;
            }
        }
        if (n < 0)
            res = (double)1.0 / (double)res;

        return res;
    }
};