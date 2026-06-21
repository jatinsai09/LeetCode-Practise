class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, cnt = 0;
        for (auto &c: moves) {
            if (c == '_') {
                cnt++;
                continue;
            }

            if (c == 'L') {
                x--;
            } else if (c == 'R') {
                x++;
            } else if (c == 'U') {
                y--;
            } else {
                y++;
            }
        }

        return abs(x) + abs(y) + cnt;
    }
};