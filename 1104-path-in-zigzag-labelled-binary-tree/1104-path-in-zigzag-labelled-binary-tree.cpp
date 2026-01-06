class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        res.push_back(label);
        int h = log2(label);

        while(h) {
            int pl = pow(2, h - 1), cr = pow(2, h + 1) - 1;
            label = pl + (cr - label) / 2;

            res.push_back(label);
            h--;
        }

        reverse(begin(res), end(res));
        return res;
    }
};