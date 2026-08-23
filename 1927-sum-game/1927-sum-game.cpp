class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), cq = 0;

        for (const auto &c: num) {
            cq += (c == '?');
        }
        if (cq & 1) {
            return true;
        }

        int s1 = 0, s2 = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                c1++;
            } else {
                s1 += (num[i] - '0');
            }
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                c2++;
            } else {
                s2 += (num[i] - '0');
            }
        }

        return (s1 - s2) * 2 != (c2 - c1) * 9;
    }
};