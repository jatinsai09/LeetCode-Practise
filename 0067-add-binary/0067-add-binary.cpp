class Solution {
public:
    string addBinary(string a, string b) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        string res;
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) {
                carry += a[i--] - '0';
            }
            if (j >= 0) {
                carry += b[j--] - '0';
            }

            res += (carry % 2) + '0';
            carry /= 2;
        }

        reverse(begin(res), end(res));
        return res;
    }
};