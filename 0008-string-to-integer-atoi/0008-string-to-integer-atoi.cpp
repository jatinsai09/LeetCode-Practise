class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, n = s.size();
        long long a = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        while (i < n) {
            if (isdigit(s[i])) {
                a = a * 10 + (s[i++] - '0');

                if (a > INT_MAX) {
                    return (sign == 1 ? INT_MAX : INT_MIN);
                }
            } else {
                return a * sign;
            }
        }

        return a * sign;
    }
};