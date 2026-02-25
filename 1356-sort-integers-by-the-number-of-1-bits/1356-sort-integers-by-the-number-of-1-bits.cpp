class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            arr[i] += __builtin_popcount(arr[i]) * 10001;
        }

        sort(begin(arr), end(arr));

        for (int i = 0; i < n; i++) {
            arr[i] %= 10001;
        }

        return arr;
    }
};