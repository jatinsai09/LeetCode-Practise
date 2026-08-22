class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0, p = 1, t = n;

        while (t) {
            int d = t % 10;
            s += d;
            p *= d;

            t /= 10;
            if (p + s > n) {
                return false;
            }
        }

        return n % (s + p) == 0;
    }
};