class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int N = 15;
        for (auto &i: arr) {
            i = __builtin_popcount(i) + i * N;
        }

        sort(begin(arr), end(arr), [&](auto &a, auto &b) {
            if (a % N == b % N) {
                return (a / N) < (b / N);
            }
            return (a % N) < (b % N);
        });

        for (auto &i: arr) {
            i /= N;
        }

        return arr;
    }
};