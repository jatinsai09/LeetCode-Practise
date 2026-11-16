class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();

        if (n <= k) {
            return s;
        }

        string res = "";
        int c = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            c++;
            sum += (s[i] - '0');

            if (i == n - 1 || c == k) {
                res += to_string(sum);
                sum = 0;
                c = 0;
            }
        }

        return digitSum(res, k);
    }
};