class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        if (n == 1) {
            if (s1[0] == s2[0]) {
                return 0;
            }

            return (s1[0] == '0' ? 1 : -1);
        }

        int res = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (s1[i] != s2[i]) {
                res++;
                if (s1[i] == '1') {
                    s1[i] = '0';

                    res += (s1[i + 1] == '0');
                    s1[i + 1] = '0';
                } else {
                    s1[i] = '1';
                }
            }
        }

        if (s1[n - 1] != s2[n - 1]) {
            res++;
            if (s1[n - 1] == '1') {
                s1[n - 1] = '0';

                res++;
                s1[n - 2] = '0';
            } else {
                s1[n - 1] = '1';
            }
        }

        return res;
    }
};