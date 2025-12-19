class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long int n = columnTitle.size(), res = 0, mul = 1;

        for (int i = n - 1; i >= 0; i--) {
            int val = columnTitle[i] - 'A' + 1;
            res = val * mul + res;
            mul *= 26;
        }

        return res;
    }
};