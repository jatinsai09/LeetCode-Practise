class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int res = 0, v1 = 0, v2 = 0;
        for (int i = 0; i < 8; i++) {
            if (startTime[i] == ':') {
                int got = (v2 - v1);
                if (i == 2) {
                    got *= 3600;
                } else {
                    got *= 60;
                }
                res += got;
                v1 = v2 = 0;
            } else {
                v1 = v1 * 10 + (startTime[i] - '0');
                v2 = v2 * 10 + (endTime[i] - '0');
            }
        }
        res += (v2 - v1);

        return res;
    }
};