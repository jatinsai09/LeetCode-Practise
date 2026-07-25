class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int l = triangle[i + 1][j];
                int r = triangle[i + 1][j + 1];

                triangle[i][j] += min(l, r);
            }
        }

        return triangle[0][0];
    }
};