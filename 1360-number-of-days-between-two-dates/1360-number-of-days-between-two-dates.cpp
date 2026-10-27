class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        if (date1 > date2) {
            swap(date1, date2);
        }

        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto isLeap = [&](int y) -> bool {
            if (y % 400 == 0) {
                return 1;
            }

            return (y % 4 == 0 && y % 100 != 0);
        };

        int res = 0;

        int y1 = stoi(date1.substr(0, 4)), y2 = stoi(date2.substr(0, 4));
        for (int i = y1 + 1; i < y2; i++) {
            res += 365 + isLeap(i);
        }

        int m1 = stoi(date1.substr(5, 2)), m2 = stoi(date2.substr(5, 2));
        if (y1 != y2) {
            for (int i = m1 - 1; i < 12; i++) {
                res += days[i];
                if (i == 1) {
                    res += isLeap(y1);
                }
            }
            for (int i = 0; i + 1 < m2; i++) {
                res += days[i];
                if (i == 1) {
                    res += isLeap(y2);
                }
            }
        }
        
        int d1 = stoi(date1.substr(8, 2)), d2 = stoi(date2.substr(8, 2));
        res -= d1;
        res += d2;

        return res;

    }
};