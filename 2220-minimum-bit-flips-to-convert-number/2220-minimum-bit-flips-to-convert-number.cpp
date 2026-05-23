class Solution {
public:
    int minBitFlips(int start, int goal) {
        int c = 0, res = start ^ goal;

        while (res) {
            c++;
            res &= (res - 1);
        }
        return c;
    }
};