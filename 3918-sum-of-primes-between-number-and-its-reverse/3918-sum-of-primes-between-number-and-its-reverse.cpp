class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }

        if (n == 2) {
            return true;
        }

        if (n % 2 == 0) {
            return false;
        }

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
    int sumOfPrimesInRange(int n) {
        int r = 0, x = n;
        while (x) {
            r = r * 10 + x % 10;
            x /= 10;
        }

        int res = 0;
        for (int i = min(n, r); i <= max(n, r); i++) {
            if (isPrime(i)) {
                res += i;
            }
        }
        return res;
    }
};