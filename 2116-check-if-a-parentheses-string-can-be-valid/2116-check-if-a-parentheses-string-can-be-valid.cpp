class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n & 1) {
            return false;
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0' || s[i] == '(') {
                cur++;
            } else {
                cur--;
            }

            if (cur < 0) {
                return false;
            }
        }

        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')') {
                cur++;
            } else {
                cur--;
            }

            if (cur < 0) {
                return false;
            }
        }

        return true;
    }
};