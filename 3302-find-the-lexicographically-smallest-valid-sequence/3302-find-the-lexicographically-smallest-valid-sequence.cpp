class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n = w1.size(), m = w2.size();

        vector<int> suf(m + 1, -1);
        suf[m] = n;
        for (int i = n - 1, j = m - 1; i >= 0; i--) {
            if (w1[i] == w2[j]) {
                suf[j--] = i;
            }
            if (j < 0) {
                break;
            }
        }

        vector<int> res(m);
        bool can = true;

        for (int i = 0, j = 0; i < n; i++) {
            if (w1[i] == w2[j]) {
                res[j++] = i;
            } else if (can && i < suf[j + 1]) {
                res[j++] = i;
                can = false;
            }

            if (j == m) {
                return res;
            }
        }

        return {};
    }
};