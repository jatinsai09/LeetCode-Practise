class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        int idx = 0, d = 1;
        vector<string> rows(numRows);

        for (auto& c : s) {
            rows[idx] += c;
            if (idx == 0) {
                d = 1;
            } else if (idx == numRows - 1) {
                d = -1;
            }
            idx += d;
        }

        string res = "";
        for (int i = 0; i < numRows; i++) {
            res += rows[i];
        }
        return res;
    }
};