class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        if (s.empty()) {
            return "";
        }
        int n = s.size();
        string res = "";

        int cols = (n + rows - 1) / rows;

        for (int j = 0; j < cols; j++) {
            int ind = j;
            while (ind < n) {
                res += s[ind];
                ind += cols + 1;
            }
        }

        while (res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};