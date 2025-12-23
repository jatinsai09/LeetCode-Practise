class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        while (n) {
            int r = n % 10;
            rev = rev * 10 + r;
            n /= 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int rev = reverse(n);
        return abs(n - rev);
    }
};