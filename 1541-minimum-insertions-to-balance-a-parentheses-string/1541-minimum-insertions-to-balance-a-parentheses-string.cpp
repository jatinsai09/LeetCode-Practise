class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), b = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                b++;
            } else {
                if (i + 1 == n || s[i + 1] != ')') {
                    res++;
                } else {
                    i++;
                }
                b--;
            }

            if (b < 0) {
                res++;
                b = 0;
            }
        }

        return res + b * 2;
    }
};