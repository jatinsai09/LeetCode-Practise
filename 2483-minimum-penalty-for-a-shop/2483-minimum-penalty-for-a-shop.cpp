class Solution {
public:
    int bestClosingTime(string cust) {
        int n = cust.size(), penalty = 0;

        for (auto &c: cust) {
            penalty += (c == 'Y');
        }

        int mn = penalty, time = 0;
        for (int i = 0; i < n; i++) {
            char c = cust[i];

            penalty += (c == 'Y' ? -1 : 1);
            if (penalty < mn) {
                time = i + 1;
                mn = penalty;
            }
        }

        return time;
    }
};