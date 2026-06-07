class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int l = max(1, n - k), r = n + k, res = 0;

        for (int i = l; i <= r; i++) {
            if (n & i) {
                continue;
            }
            res += i;
        }
        return res;
    }
};