class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.size();
        string res = "";

        int c1 = 0, c0 = 0;
        for (auto &c: t) {
            (c == '0' ? c0++ : c1++);
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (c0) {
                    c0--;
                    res += "1";
                } else {
                    c1--;
                    res += "0";
                }
            } else {
                if (c1) {
                    c1--;
                    res += "1";
                } else {
                    c0--;
                    res += "0";
                }
            }
        }
        
        return res;
    }
};