class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> f;
        for (auto &i: deck) {
            f[i]++;
        }

        int g = 0;
        for (auto &[k, freq]: f) {
            g = __gcd(freq, g);
        }

        return g > 1;
    }
};