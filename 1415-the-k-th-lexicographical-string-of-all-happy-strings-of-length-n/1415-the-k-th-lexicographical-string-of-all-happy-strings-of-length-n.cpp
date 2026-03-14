class Solution {
public:
    string res;
    void give(string s, int len, int& n, int& cnt) {
        if (len == n) {
            if (--cnt == 0) {
                res = s;
            }
            return;
        }

        for (char c = 'a'; c < 'd'; c++) {
            if (s.empty() || s.back() != c) {
                give(s + c, len + 1, n, cnt);
            }
            if (cnt == 0) {
                return;
            }
        }
    }
    string getHappyString(int n, int k) {
        give("", 0, n, k);
        return res;
    }
};