class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int buf = 0, p = 0;

        for (auto &c : moves) {
            if (c == '_') {
                buf++;
            } else {
                p += (c == 'L' ? -1 : 1);
            }
        }

        return abs(p) + buf;
    }
};