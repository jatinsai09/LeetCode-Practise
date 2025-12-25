class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansrow;
        ansrow.push_back(1);
        
        for (int col = 2; col <= row; col++) {
            ans *= (row - (col - 1));
            ans /= (col - 1);
            ansrow.push_back(ans);
        }
        return ansrow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int row = 1; row <= numRows; row++) {
            vector<int> t = generateRow(row);
            res.push_back(t);
        }
        return res;
    }
};