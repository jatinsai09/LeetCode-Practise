class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, cnt = 0;
        for (auto &e : events) {
            cnt += (e == "W");
            score += (e == "NB" || e == "WD");
            if (isdigit(e[0])) {
                score += (e[0] - '0');
            }

            if (cnt == 10) {
                break;
            }
        }

        return {score, cnt};
    }
};