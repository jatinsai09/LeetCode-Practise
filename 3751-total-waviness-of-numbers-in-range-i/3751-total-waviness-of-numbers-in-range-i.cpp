class Solution {
public:
    int give(int n) {
        string s = to_string(n);
        int m = s.size(), g = 0;

        for (int i = 1; i < m - 1; i++) {
            if (s[i] == s[i - 1] || s[i] == s[i + 1]) {
                continue;
            }
            
            g += ((s[i] > s[i - 1]) == (s[i] > s[i + 1]));
        }

        return g;
    }

    int totalWaviness(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; i++) {
            res += give(i);
        }
        return res;
    }
};