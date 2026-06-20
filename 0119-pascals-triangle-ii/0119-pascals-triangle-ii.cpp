class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);

        long cur = 1;
        for (int i = 1, j = rowIndex; i <= rowIndex / 2; i++, j--) {
            cur *= j;
            cur /= i;

            res[i] = res[rowIndex - i] = cur;
        }
        return res;
    }
};