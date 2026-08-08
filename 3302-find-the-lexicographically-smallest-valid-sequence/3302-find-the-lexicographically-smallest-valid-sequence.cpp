class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n = w1.size(), m = w2.size();

        vector<int> suf(n);
        int c = 0, j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = c;
            if (j >= 0 && w1[i] == w2[j]) {
                c++;
                j--;
            }
        }

        vector<int> res;
        bool can = true;
        j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (w1[i] == w2[j]) {
                res.push_back(i);
                j++;
            } else if (can && suf[i] >= m - (j + 1)) {
                can = false;
                res.push_back(i);
                j++;
            }
        }

        if (j == m) {
            return res;
        }
        return {};
    }
};