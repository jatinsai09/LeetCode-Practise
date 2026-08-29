class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) {
        int n = arr.size();

        vector<int> lis, res(n);
        int sz = 0;
        for (int i = 0; i < n; i++) {
            if (lis.empty() || lis.back() <= arr[i]) {
                lis.push_back(arr[i]);
                sz++;

                res[i] = sz;
            } else {
                int ind = upper_bound(begin(lis), end(lis), arr[i]) - begin(lis);

                lis[ind] = arr[i];
                res[i] = ind + 1;
            }
        }
        return res;
    }
};