class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int res = 0;

        for (int i = left; i <= right; i++) {
            int bits = 0, n = i;
            while (n) {
                bits += (n & 1);
                n >>= 1;
            }
            res += primes.count(bits);
        }

        return res;
    }
};