class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> s = arr;

        sort(begin(s), end(s));
        s.erase(unique(begin(s), end(s)), end(s));

        for (int i = 0; i < n; i++) {
            arr[i] = lower_bound(begin(s), end(s), arr[i]) - begin(s) + 1;
        }

        return arr;
    }
};