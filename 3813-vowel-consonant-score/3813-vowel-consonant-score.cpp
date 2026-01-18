class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        string vow = "aeiou";

        for (auto& ch : s) {
            if (ch == ' ' || isdigit(ch)) {
                continue;
            }

            if (vow.find(ch) != string::npos) {
                v++;
            } else {
                c++;
            }
        }

        return c == 0 ? 0 : v / c;
    }
};