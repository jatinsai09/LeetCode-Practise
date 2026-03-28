class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '@');
        char cur = 'a';

        for (int i = 0; i < n; i++) {
            if (s[i] != '@') {
                continue;
            }

            if (cur > 'z') {
                return "";
            }

            s[i] = cur;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    s[j] = cur;
                }
            }
            cur++;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                        continue;
                    }
                    if (lcp[i][j] != 1 + lcp[i + 1][j + 1]) {
                        return "";
                    }
                } else {
                    if (lcp[i][j] != 0) {
                        return "";
                    }
                }
            }
        }
        return s;
    }
};