class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        res.push_back(label);
        int h = log2(label);

        while(h) {
            int prevLow = pow(2, h - 1), curHigh = pow(2, h + 1) - 1;
            label = prevLow + (curHigh - label) / 2;

            res.push_back(label);
            h--;
        }

        reverse(begin(res), end(res));
        return res;
    }
};