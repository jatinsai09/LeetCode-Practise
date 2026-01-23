class Solution {
public:
    int minAddToMakeValid(string s) {
        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);

        int cur = 0, c = 0;
        for (auto& ch : s) {
            (ch == '(' ? cur++ : cur--);
            if (cur < 0) {
                c++;
                cur++;
            }
        }
       
        return c + cur;
    }
};