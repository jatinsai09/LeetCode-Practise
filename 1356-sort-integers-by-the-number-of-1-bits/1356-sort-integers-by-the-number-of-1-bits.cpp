class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int N = 10001;
        for (auto &i: arr) {
            i += __builtin_popcount(i) * N;
        }

        sort(begin(arr), end(arr));

        for (auto &i: arr) {
            i %= N;
        }

        return arr;
    }
};