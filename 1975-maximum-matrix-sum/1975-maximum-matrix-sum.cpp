class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int mini = INT_MAX, c = 0;
        long long sum = 0;

        for (auto& arr : matrix) {
            for (auto& i : arr) {
                sum += abs(i);
                if (i < 0) {
                    c++;
                }
                mini = min(abs(i), mini);
            }
        }

        if (c & 1) {
            sum -= (mini << 1);
        }

        return sum;
    }
};