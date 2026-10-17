class Solution {
public:
    int digitSum(int n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    int minSwaps(vector<int>& a) {
        int n = a.size();
        vector<int> b = a;

        sort(begin(b), end(b), [&](int x, int y) {
            int sumX = digitSum(x), sumY = digitSum(y);
            if (sumX == sumY) {
                return x < y;
            }
            return sumX < sumY;
        });

        unordered_map<int, int> og;
        for (int i = 0; i < n; i++) {
            og[b[i]] = i;
        }

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            while (i != og[a[i]]) {
                swap(a[i], a[og[a[i]]]);
                swaps++;
            }
        }
        return swaps;
    }
};