class Solution {
public:
    int minimumK(vector<int>& nums) {
        long long l = 1, r = 1e8;

        long long m;
        while (l <= r) {
            m = l + (r - l) / 2;

            long long got = 0;
            for (auto &i: nums) {
                got += (i + m - 1) / m;
            }

            if (got > m * m) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }
};