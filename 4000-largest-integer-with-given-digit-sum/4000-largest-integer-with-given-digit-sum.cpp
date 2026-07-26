class Solution {
public:
    int largestInteger(int n, int s) {
        if (n * 9 < s) {
            return -1;
        }
        int res = 0;

        for (int i = 0; i < n; i++) {
            int d = min(s, 9);
            res = res * 10 + d;
            s -= d;
        }

        return res;
    }
};