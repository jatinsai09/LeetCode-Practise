class Solution {
public:
    int minAddToMakeValid(string s) {
        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);

        int b = 0, res = 0;
        for (const auto& ch : s) {
            b += (ch == '(' ? 1 : -1);

            if (b < 0) {
                res++;
                b = 0;
            }
        }
        res += b;

        return res;
    }
};