class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n = a.size(), i = 0, j = 1;
        vector<int> res(n);

        for (const auto& it: a) {
            if (it > 0) {
                res[i] = it;
                i += 2;
            } else {
                res[j] = it;
                j += 2;
            }
        }

        return res;
    }
};