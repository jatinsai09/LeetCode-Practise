class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;

        for (auto &row : grid) {
            for (auto &i : row) {
                v.push_back(i);
            }
        }

        for (auto &i : v) {
            if (abs(i - v[0]) % x) {
                return -1;
            } 
        }

        int n = v.size();
        sort(begin(v), end(v));
        int median = v[n / 2];

        int res = 0;
        for (auto &i : v) {
            res += abs(i - median) / x;
        }

        return res;
    }
};