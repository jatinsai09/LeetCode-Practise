class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> res = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                              "Thursday", "Friday", "Saturday"};

        int days = 0;

        for (int y = 1971; y < year; y++) {
            days += (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 2 : 1;
        }

        vector<int> md = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            md[1] = 29;
        }

        for (int i = 0; i < month - 1; i++) {
            days += md[i];
        }

        days += day;

        return res[(days + 4) % 7]; // Jan 1, 1971 = Friday (index 5)
    }
};