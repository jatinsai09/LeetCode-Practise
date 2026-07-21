class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;

        long long p = n;
        if (p < 0) {
            p *= -1;
        }

        while (p) {
            if (p & 1) {
                res *= x;
            }
            
            x *= x;
            p >>= 1;
            
        }

        if (n < 0) {
            res = (double)1.0 / res;
        }

        return res;
    }
};