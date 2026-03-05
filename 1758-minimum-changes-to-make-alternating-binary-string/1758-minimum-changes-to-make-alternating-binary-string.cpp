class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int p1 = 0, p2 = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] - '0' != i % 2) {
                p1++;
            } else {
                p2++;
            }
        }

        return min(p1, p2);
    }
};