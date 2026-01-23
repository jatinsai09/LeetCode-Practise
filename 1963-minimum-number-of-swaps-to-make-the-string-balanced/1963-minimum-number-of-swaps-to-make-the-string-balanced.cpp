class Solution {
public:
    int minSwaps(string s) {
        int c = 0, res = 0;
        for (auto& ch : s) {
            if (ch == '[') {
                c++;
            } else {
                (c > 0 ? c-- : res++);
            }
        }

        return (res + 1) >> 1;
    }
};