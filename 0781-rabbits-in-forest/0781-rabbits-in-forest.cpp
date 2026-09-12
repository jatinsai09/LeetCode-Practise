class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> f;
        for (const auto &i: answers) {
            f[i]++;
        }

        int res = 0;
        for (const auto &[k, freq]: f) {
            int types = (freq + k) / (k + 1);

            res += types * (k + 1);
        }
        return res;
    }
};