class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        int ri = 0, dr = -1;
        vector<string> rows(numRows);

        for (const auto& c : s) {
            rows[ri] += c;
            if (ri == 0 || ri == numRows - 1) {
                dr *= -1;
            }
            ri += dr;
        }

        string res = "";
        for (int i = 0; i < numRows; i++) {
            res += rows[i];
        }
        return res;
    }
};