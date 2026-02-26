class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), c1 = 0;
        for (auto &c: s) {
            c1 += (c == '1');
        }

        if (c1 == 1) {
            return n - 1;
        }

        int res = n, c0 = n - c1;
        int j = n - 1;
        while (s[j] == '0') {
            j--;
            c0--;
        }
        res += c0 + 1;

        return res;
    }
};