class Solution {
public:
    bool canAliceWin(int n) {
        int cur = 10, t = 0;
        while (n >= cur) {
            n -= cur;
            cur--;
            t ^= 1;
        }

        return t;
    }
};