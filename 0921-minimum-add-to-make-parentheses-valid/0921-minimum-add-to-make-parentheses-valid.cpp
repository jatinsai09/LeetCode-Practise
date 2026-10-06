class Solution {
public:
    int minAddToMakeValid(string s) {
        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);

        int op = 0, cl = 0, c = 0;
        for (auto& ch : s) {
            (ch == '(' ? op++ : cl++);

            if (cl > op) {
                c++;
                op++;
            }
        }
        if (op > cl) {
            c += (op - cl);
        }

        return c;
    }
};