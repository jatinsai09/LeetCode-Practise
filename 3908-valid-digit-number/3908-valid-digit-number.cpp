class Solution {
public:
    bool validDigit(int n, int x) {
        bool yes = false;
        while (n >= 10) {
            if (n % 10 == x) {
                yes = true;
            }
            n /= 10;
        }
        return yes && n != x;
    }
};