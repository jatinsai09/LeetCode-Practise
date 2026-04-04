class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        if (rows == 1) {
            return s;
        }

        int n = s.size();
        string res = "";

        int cols = n / rows;

        for (int j = 0; j < cols; j++) {
            int ind = j;
            while (ind < n) {
                res += s[ind];
                ind += cols + 1;
            }
        }

        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};