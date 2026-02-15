class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int, int> f, ff;

        for (auto &i: nums) {
            f[i]++;
        }

        for (auto &it: f) {
            ff[it.second]++;
        }

        for (auto &i: nums) {
            if (ff[f[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};