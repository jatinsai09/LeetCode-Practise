class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);

        int j = rowIndex;
        long cur = 1;
        for (int i = 1; i <= rowIndex / 2; i++) {
            cur *= j;
            cur /= i;
            j--;

            res[i] = cur;
            res[rowIndex - i] = cur;
        }
        return res;
    }
};