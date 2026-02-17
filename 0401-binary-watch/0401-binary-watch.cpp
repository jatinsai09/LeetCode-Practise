class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<vector<int>> hours(5);
        vector<vector<int>> minutes(7);

        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                for (int c = 0; c < 2; c++) {
                    for (int d = 0; d < 2; d++) {
                        int sum = a * 1 + b * 2 + c * 4 + d * 8;
                        int cnt = a + b + c + d;

                        if (sum < 12) {
                            hours[cnt].push_back(sum);
                        }
                    }
                }
            }
        }

        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                for (int c = 0; c < 2; c++) {
                    for (int d = 0; d < 2; d++) {
                        for (int e = 0; e < 2; e++) {
                            for (int f = 0; f < 2; f++) {
                                int sum = a * 1 + b * 2 + c * 4 + d * 8 +
                                             e * 16 + f * 32;
                                int cnt = a + b + c + d + e + f;

                                if (sum < 60) {
                                    minutes[cnt].push_back(sum);
                                }
                            }
                        }
                    }
                }
            }
        }

        vector<string> res;

        for (int h = 0; h <= 4; h++) {
            int m = turnedOn - h;

            if (m < 0 || m > 6)  {
                continue;
            }

            for (auto& hb: hours[h]) {
                for (auto &mb: minutes[m]) {
                    string s = to_string(hb) + ":";

                    if (mb < 10) {
                        s += "0";
                    } 
                    s += to_string(mb);

                    res.push_back(s);
                }
            }
        }

        return res;
    }
};