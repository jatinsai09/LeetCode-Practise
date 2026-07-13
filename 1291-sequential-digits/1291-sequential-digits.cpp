class Solution {
public:
    inline static vector<int> valid;
    inline static bool init = []() {
        queue<int> q;
        for (int i = 1; i < 9; i++) {
            q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            valid.push_back(cur);

            int ld = cur % 10;
            if (ld < 9) {
                q.push(cur * 10 + (ld + 1));
            }
        }

        return 1;
    }();
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for (auto &i: valid) {
            if (i >= low && i <= high) {
                res.push_back(i);
            }
        }

        return res;
    }
};