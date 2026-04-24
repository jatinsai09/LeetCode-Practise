class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int buf = 0, p = 0;

        for (auto &c : moves) {
            buf += (c == '_');
            p += (c == 'R') - (c == 'L');
        }

        return abs(p) + buf;
    }
};