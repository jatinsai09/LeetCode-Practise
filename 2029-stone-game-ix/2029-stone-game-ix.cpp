class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size(), f[3] = {0, 0, 0};

        for (const auto &i: stones) {
            f[i % 3]++;
        }

        if (f[0] % 2 == 0) {
            return f[1] > 0 && f[2] > 0;
        } else {
            return abs(f[2] - f[1]) > 2;
        }
    }
};