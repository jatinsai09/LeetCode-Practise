class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int c5 = 0, c10 = 0;
        for (const auto& i : bills) {
            if (i == 5) {
                c5++;
            } else if (i == 10) {
                c10++;
                if (c5) {
                    c5--;
                } else {
                    return false;
                }
            } else {
                if (c10 && c5) {
                    c5--;
                    c10--;
                } else if (c5 >= 3) {
                    c5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};