class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        for (auto &i: arr1) {
            int yes = 0;
            for (auto &j: arr2) {
                yes |= (abs(i - j) <= d);
            }

            res += !yes;
        }

        return res;
    }
};