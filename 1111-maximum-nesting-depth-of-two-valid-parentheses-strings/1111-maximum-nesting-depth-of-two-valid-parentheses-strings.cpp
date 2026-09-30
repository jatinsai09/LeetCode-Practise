class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;

        int d = 0;
        for (const auto &c: seq) {
            if (c == '(') {
                res.push_back(d & 1);
                d++;
            } else {
                d--;
                res.push_back(d & 1);
            }
        }

        return res;
    }
};