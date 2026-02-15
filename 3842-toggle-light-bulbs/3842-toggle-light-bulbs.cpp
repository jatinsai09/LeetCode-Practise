class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> f(101), res;

        for (auto &i: bulbs) {
            f[i]++;
        }

        for (int i = 1; i <= 100; i++) {
            if (f[i] & 1) {
                res.push_back(i);
            }
        }

        return res;
    }
};